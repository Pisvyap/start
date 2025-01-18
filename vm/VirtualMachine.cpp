#include "VirtualMachine.h"
#include "llvm/ADT/SmallString.h"
#include <stdexcept>
#include <iostream>

namespace vm {

    VirtualMachine::VirtualMachine() = default;

    void VirtualMachine::execute(const std::vector<bc::Instruction> &bytecode) {
        for (size_t i = 0; i < bytecode.size(); i++) {
            if (bytecode[i].op == bc::LABEL) {
                handleLabel(bytecode[i], i);
            } else if (bytecode[i].op == bc::FUNC_BEGIN) {
                functions.insert(std::make_pair(bytecode[i].name, i));
            }
        }
        while (instructionPointer < bytecode.size()) {
            const auto &instr = bytecode[instructionPointer];

            switch (instr.op) {
                case bc::LOAD_CONST:
                    handleLoadConst(instr);
                    break;

                case bc::STORE_VAR:
                    handleStoreVar(instr);
                    break;

                case bc::LOAD_VAR:
                    handleLoadVar(instr);
                    break;

                case bc::ADD:
                    handleAdd();
                    break;

                case bc::SUB:
                    handleSub();
                    break;

                case bc::MUL:
                    handleMul();
                    break;

                case bc::DIV:
                    handleDiv();
                    break;

                case bc::PRINT:
                    handlePrint();
                    break;

                case bc::ALLOC:
                    handleAlloc(instr);
                    break;

                case bc::STORE_IN_ARRAY:
                    handleStoreInArray();
                    break;

                case bc::LOAD_FROM_ARRAY:
                    handleLoadFromArray();
                    break;

                case bc::PASS:
                    handlePass();
                    break;

                case bc::LOAD_PTR:
                    handleLoadPtr(instr);
                    break;

                case bc::STORE_PTR:
                    handleStorePtr(instr);
                    break;

                case bc::FUNC_BEGIN:
                    while (bytecode[instructionPointer].op != bc::OP::FUNC_END) {
                        instructionPointer++;
                    }
                    //handleFuncBegin();
                    break;

                case bc::FUNC_END:
                    handleFuncEnd();
                    break;

                case bc::RETURN:
                    handleReturn();
                    break;

                case bc::CALL:
                    handleCall(instr);
                    break;

                case bc::LABEL:
                    handlePass();
                    break;

                case bc::JUMP_IF_FALSE:
                    handleJumpIfFalse(instr, instructionPointer);
                    break;

                case bc::JUMP:
                    handleJump(instr, instructionPointer);
                    break;

                case bc::GT:
                    handleGt();
                    break;

                case bc::GE:
                    handleGe();
                    break;

                case bc::LT:
                    handleLt();
                    break;

                case bc::LE:
                    handleLe();
                    break;

                case bc::EQ:
                    handleEq();
                    break;

                case bc::NE:
                    handleNe();
                    break;

                case bc::NOT:
                    handleNot();
                    break;

                default:
                    handleUnsupported(instr.op);
            }

            instructionPointer++;
        }
    }

    void VirtualMachine::handleLoadConst(const bc::Instruction &instr) {
        if (!instr.has_operand) {
            throw std::runtime_error("LOAD_CONST missing operand");
        }
        dataStack.push_back(instr.operand);
    }

    void VirtualMachine::handleStoreVar(const bc::Instruction &instr) {
        if (!instr.has_name) {
            throw std::runtime_error("STORE_VAR missing variable name");
        }
        vars[instr.name] = dataStack.back();
        dataStack.pop_back();
    }

    void VirtualMachine::handleLoadVar(const bc::Instruction &instr) {
        if (!instr.has_name) {
            throw std::runtime_error("LOAD_VAR missing variable name");
        }
        if (vars.find(instr.name) == vars.end()) {
            throw std::runtime_error("Variable not found: " + instr.name);
        }
        dataStack.push_back(vars[instr.name]);
    }

    void VirtualMachine::handleAdd() {
        if (dataStack.size() < 2) {
            throw std::runtime_error("Stack underflow on ADD");
        }
        llvm::APInt b = dataStack.back();
        dataStack.pop_back();
        llvm::APInt a = dataStack.back();
        dataStack.pop_back();
        dataStack.push_back(a + b);
    }

    void VirtualMachine::handleSub() {
        if (dataStack.size() < 2) {
            throw std::runtime_error("Stack underflow on SUB");
        }
        llvm::APInt b = dataStack.back();
        dataStack.pop_back();
        llvm::APInt a = dataStack.back();
        dataStack.pop_back();
        dataStack.push_back(a - b);
    }

    void VirtualMachine::handleMul() {
        if (dataStack.size() < 2) {
            throw std::runtime_error("Stack underflow on MUL");
        }
        llvm::APInt b = dataStack.back();
        dataStack.pop_back();
        llvm::APInt a = dataStack.back();
        dataStack.pop_back();
        dataStack.push_back(a * b);
    }

    void VirtualMachine::handleDiv() {
        if (dataStack.size() < 2) {
            throw std::runtime_error("Stack underflow on DIV");
        }
        llvm::APInt b = dataStack.back();
        dataStack.pop_back();
        if (b == 0) {
            throw std::runtime_error("Division by zero");
        }
        llvm::APInt a = dataStack.back();
        dataStack.pop_back();
        dataStack.push_back(a.sdiv(b));
    }

    void VirtualMachine::handleGt() {
        if (dataStack.size() < 2) {
            throw std::runtime_error("Stack underflow on GT");
        }
        llvm::APInt b = dataStack.back();
        dataStack.pop_back();
        llvm::APInt a = dataStack.back();
        dataStack.pop_back();
        dataStack.push_back(llvm::APInt(128, b.sgt(a)));
    }

    void VirtualMachine::handleGe() {
        if (dataStack.size() < 2) {
            throw std::runtime_error("Stack underflow on GE");
        }
        llvm::APInt b = dataStack.back();
        dataStack.pop_back();
        llvm::APInt a = dataStack.back();
        dataStack.pop_back();
        dataStack.push_back(llvm::APInt(128, b.sge(a)));
    }

    void VirtualMachine::handleLt() {
        if (dataStack.size() < 2) {
            throw std::runtime_error("Stack underflow on LT");
        }
        llvm::APInt b = dataStack.back();
        dataStack.pop_back();
        llvm::APInt a = dataStack.back();
        dataStack.pop_back();
        dataStack.push_back(llvm::APInt(128, b.slt(a)));
    }

    void VirtualMachine::handleLe() {
        if (dataStack.size() < 2) {
            throw std::runtime_error("Stack underflow on LE");
        }
        llvm::APInt b = dataStack.back();
        dataStack.pop_back();
        llvm::APInt a = dataStack.back();
        dataStack.pop_back();
        dataStack.push_back(llvm::APInt(128, b.sle(a)));
    }

    void VirtualMachine::handleEq() {
        if (dataStack.size() < 2) {
            throw std::runtime_error("Stack underflow on EQ");
        }
        llvm::APInt b = dataStack.back();
        dataStack.pop_back();
        llvm::APInt a = dataStack.back();
        dataStack.pop_back();
        dataStack.push_back(llvm::APInt(128, a.eq(b)));
    }

    void VirtualMachine::handleNe() {
        if (dataStack.size() < 2) {
            throw std::runtime_error("Stack underflow on NE");
        }
        llvm::APInt b = dataStack.back();
        dataStack.pop_back();
        llvm::APInt a = dataStack.back();
        dataStack.pop_back();
        dataStack.push_back(llvm::APInt(128, !a.eq(b)));
    }


    void VirtualMachine::handlePrint() {
        if (dataStack.empty()) {
            throw std::runtime_error("Stack underflow on PRINT");
        }
        llvm::SmallString<40> operandBuffer;
        dataStack.back().toString(operandBuffer, 10, true);
        std::cout << operandBuffer.c_str() << std::endl;
        dataStack.pop_back();
    }

    void VirtualMachine::handleAlloc(const bc::Instruction &instr) {
        if (!instr.has_operand) {
            throw std::runtime_error("ALLOC missing size operand");
        }

        if (!instr.operand.isIntN(sizeof(size_t) * 8)) {
            throw std::runtime_error("ALLOC operand exceeds platform size limit");
        }

        auto allocSize = static_cast<size_t>(instr.operand.getLimitedValue());

        // Выделяем память через GC_MALLOC
        void *allocatedMemory = GC_MALLOC(allocSize);
        if (!allocatedMemory) {
            throw std::runtime_error("Memory allocation failed");
        }

        // Сохраняем указатель как llvm::APInt в стек
        llvm::APInt ptrValue(sizeof(uintptr_t) * 8, reinterpret_cast<uintptr_t>(allocatedMemory));
        dataStack.push_back(ptrValue);
    }

    void VirtualMachine::handleStoreInArray() {
        llvm::APInt value = dataStack.back();
        dataStack.pop_back();

        llvm::APInt index = dataStack.back();
        dataStack.pop_back();

        llvm::APInt arrayPtrAPInt = dataStack.back();
        dataStack.pop_back();

        // Преобразуем указатель в реальный указатель на массив
        uint64_t *arrayPtr = reinterpret_cast<uint64_t *>(arrayPtrAPInt.getLimitedValue());

        uint64_t indexValue = index.getLimitedValue();

        if (!arrayPtr) {
            throw std::runtime_error("Null pointer dereferenced");
        }

        // Сохраняем значение в массиве
        llvm::APInt *targetCell = reinterpret_cast<llvm::APInt *>(&arrayPtr[indexValue]);
        *targetCell = value;
    }

    void VirtualMachine::handleLoadFromArray() {
        llvm::APInt index = dataStack.back();
        dataStack.pop_back();

        llvm::APInt arrayPtrAPInt = dataStack.back();
        dataStack.pop_back();

        // Преобразуем указатель из APInt в реальный указатель на массив
        llvm::APInt *arrayPtr = reinterpret_cast<llvm::APInt *>(arrayPtrAPInt.getLimitedValue());

        if (!arrayPtr) {
            throw std::runtime_error("Null pointer dereferenced");
        }

        uint64_t indexValue = index.getLimitedValue();

        llvm::APInt value = arrayPtr[indexValue];

        dataStack.push_back(value);
    }

    void VirtualMachine::handleUnsupported(bc::OP op) {
        std::cerr << "Warning: Unsupported operation encountered: " << op << std::endl;
    }


    void VirtualMachine::handlePass() {
        //Курим бамбук
    }

    void VirtualMachine::handleLoadPtr(const bc::Instruction &instr) { //Наскок я понял, тут отличие только в том, что это указатели, поэтому тот же что и для VAR
        if (!instr.has_name) {
            throw std::runtime_error("LOAD_PTR missing ptr name");
        }
        if (vars.find(instr.name) == vars.end()) {
            throw std::runtime_error("Ptr not found: " + instr.name);
        }
        dataStack.push_back(vars[instr.name]);
    }

    void VirtualMachine::handleStorePtr(const bc::Instruction &instr) {
        if (!instr.has_name) {
            throw std::runtime_error("STORE_PTR missing ptr name");
        }
        vars[instr.name] = dataStack.back();
        dataStack.pop_back();
    }

    void VirtualMachine::handleFuncBegin() {

    }

    void VirtualMachine::handleFuncEnd() {}

    void VirtualMachine::handleReturn() {}

    void VirtualMachine::handleCall(const bc::Instruction &instr) {
        if (dataStack.size() < instr.operand.getLimitedValue()) {
            throw std::runtime_error("Stack underflow on Call");
        }
    }

    void VirtualMachine::handleLabel(const bc::Instruction &instr, size_t &currentPointer) {
        labels.insert(std::make_pair(instr.operand.getLimitedValue(), currentPointer)); //Тут у него какие-то вопросы к APInt, пока так (хотя я сомневаюсь что нам понадобится так много якорей)
    }

    void VirtualMachine::handleJumpIfFalse(const bc::Instruction &instr, size_t &currentPointer) {
        if (dataStack.empty()) {
            throw std::runtime_error("Stack underflow on JumpIfFalse");
        }
        auto toJumpIfFalse = dataStack.back();
        dataStack.pop_back();
        if (toJumpIfFalse == 0) {
            if (labels.find(instr.operand.getLimitedValue()) != labels.end()) {
                currentPointer = labels[instr.operand.getLimitedValue()];
            }
        }
    }

    void VirtualMachine::handleJump(const bc::Instruction &instr, size_t &currentPointer) {
        currentPointer = labels[instr.operand.getLimitedValue()];
    }

    void VirtualMachine::handleNot() {
        if (dataStack.empty()) {
            throw std::runtime_error("Stack underflow on Not");
        }
        llvm::APInt a = dataStack.back();
        dataStack.pop_back();
        dataStack.push_back(a == 1 ? llvm::APInt(1, 0) : llvm::APInt(1, 1));
    }
}