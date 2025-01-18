#include "VirtualMachine.h"
#include <stdexcept>
#include <iostream>

namespace vm {

    // Конструктор
    VirtualMachine::VirtualMachine() {
        GC_INIT(); // Инициализация BDWGC
    }

    void VirtualMachine::execute(const std::vector<bc::Instruction> &bytecode) {
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
                    handleLoadPtr();
                    break;

                case bc::STORE_PTR:
                    handleStorePtr();
                    break;

                case bc::FUNC_BEGIN:
                    handleFuncBegin();
                    break;

                case bc::FUNC_END:
                    handleFuncEnd();
                    break;

                case bc::RETURN:
                    handleReturn();
                    break;

                case bc::LABEL:
                    handleLabel();
                    break;

                case bc::JUMP_IF_FALSE:
                    handleJumpIfFalse();
                    break;

                case bc::JUMP:
                    handleJump();
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
        uint64_t b = dataStack.back();
        dataStack.pop_back();
        uint64_t a = dataStack.back();
        dataStack.pop_back();
        dataStack.push_back(a + b);
    }

    void VirtualMachine::handlePrint() {
        if (dataStack.empty()) {
            throw std::runtime_error("Stack underflow on PRINT");
        }
        std::cout << "Output: " << dataStack.back() << std::endl;
        dataStack.pop_back();
    }

    void VirtualMachine::handleAlloc(const bc::Instruction &instr) {
        if (!instr.has_operand) {
            throw std::runtime_error("ALLOC missing size operand");
        }
        // Выделяем память через GC_MALLOC
        dataStack.push_back(reinterpret_cast<uint64_t>(GC_MALLOC(instr.operand)));
    }

    void VirtualMachine::handleStoreInArray() {
        uint64_t value = dataStack.back();
        dataStack.pop_back();
        uint64_t index = dataStack.back();
        dataStack.pop_back();
        uint64_t *arrayPtr = reinterpret_cast<uint64_t *>(dataStack.back());
        dataStack.pop_back();
        arrayPtr[index] = value;
    }

    void VirtualMachine::handleLoadFromArray() {
        uint64_t index = dataStack.back();
        dataStack.pop_back();
        uint64_t *arrayPtr = reinterpret_cast<uint64_t *>(dataStack.back());
        dataStack.pop_back();
        dataStack.push_back(arrayPtr[index]);
    }

    void VirtualMachine::handleUnsupported(bc::OP op) {
        std::cerr << "Warning: Unsupported operation encountered: " << op << std::endl;
    }


    void VirtualMachine::handlePass() {}

    void VirtualMachine::handleLoadPtr() {}

    void VirtualMachine::handleStorePtr() {}

    void VirtualMachine::handleFuncBegin() {}

    void VirtualMachine::handleFuncEnd() {}

    void VirtualMachine::handleReturn() {}

    void VirtualMachine::handleLabel() {}

    void VirtualMachine::handleJumpIfFalse() {}

    void VirtualMachine::handleJump() {}

    void VirtualMachine::handleGt() {}

    void VirtualMachine::handleGe() {}

    void VirtualMachine::handleLt() {}

    void VirtualMachine::handleLe() {}

    void VirtualMachine::handleEq() {}

    void VirtualMachine::handleNe() {}

    void VirtualMachine::handleNot() {}
}