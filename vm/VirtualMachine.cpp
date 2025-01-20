#include "VirtualMachine.h"
#include "llvm/ADT/SmallString.h"
#include <stdexcept>
#include <iostream>

namespace vm {

    VirtualMachine::VirtualMachine() = default;

    void VirtualMachine::execute(const std::vector<bc::Instruction>& bytecode) {
        size_t funcStart = -1;
        for (size_t i = 0; i < bytecode.size(); i++) {
            const auto& instr = bytecode[i];
            if (instr.op == bc::MISSIYA_NACHALO) {
                handleFuncBegin(instr);
                funcStart = i;
            } else if (instr.op == bc::MISSIYA_KONEC) {
                if (funcStart == -1) {
                    throw std::runtime_error("FUNC_END without matching FUNC_BEGIN");
                }

                functions[bytecode[funcStart].name] = {funcStart, i};
                funcStart = -1;
            } else if ( instr.op == bc::METKA) {

                if (!instr.has_operand) {
                    throw std::runtime_error("LABEL missing operand");
                }
                handleLabel(instr,i);
            }
        }

        if (funcStart != -1) {
            throw std::runtime_error("FUNC_BEGIN without matching FUNC_END");
        }

        while (instructionPointer < bytecode.size()) {
            const auto& instr = bytecode[instructionPointer];

            if (isFunctionExec) {
                executeInstruction(instr);
                continue;
            }

            bool insideFunction = false;
            for (const auto& [funcName, range] : functions) {
                auto [start, end] = range;
                if (instructionPointer >= start && instructionPointer <= end) {
                    insideFunction = true;
                    break;
                }
            }
            if (insideFunction) {
                instructionPointer++;
                continue;
            }

            executeInstruction(instr);
        }
    }

    void VirtualMachine::executeInstruction(const bc::Instruction& instr)  {
        switch (instr.op) {
            case bc::GRUZY_POSTOYANNUYU:
                handleLoadConst(instr);
                break;

            case bc::HRANY_PEREMENNUYU:
                handleStoreVar(instr);
                break;

            case bc::GRUZY_PEREMENNUYU:
                handleLoadVar(instr);
                break;

            case bc::DOBAV:
                handleAdd();
                break;

            case bc::VICHTY:
                handleSub();
                break;

            case bc::UMNOZH:
                handleMul();
                break;

            case bc::DELY:
                handleDiv();
                break;

            case bc::VIVEDY:
                handlePrint();
                break;

            case bc::VIDAY:
                handleAlloc();
                break;

            case bc::GRUZY_V_SGRUDU:
                handleStoreInArray();
                break;

            case bc::GRUZY_IZ_SGRUDY:
                handleLoadFromArray();
                break;

            case bc::PUSTAYA:
                handlePass();
                break;

            case bc::GRUZY_UKAZATEL:
                handleLoadPtr(instr);
                break;

            case bc::HRANY_UKAZATEL:
                handleStorePtr(instr);
                break;

            case bc::MISSIYA_NACHALO:
                handleFuncBegin(instr);
                break;

            case bc::MISSIYA_KONEC:
                handleFuncEnd();
                break;

            case bc::VERNUT:
                handleReturn();
                break;

            case bc::ZOVY:
                handleCall(instr);
                break;

            case bc::METKA:
                handlePass();
                break;

            case bc::PRIGAY_ESLI_NEPRAVDA:
                handleJumpIfFalse(instr, instructionPointer);
                break;

            case bc::PRIGAY:
                handleJump(instr, instructionPointer);
                break;

            case bc::BOLSHE:
                handleGt();
                break;

            case bc::BOLSHE_ILI_RAVNO:
                handleGe();
                break;

            case bc::MENSHE:
                handleLt();
                break;

            case bc::MENSHE_ILI_RAVNO:
                handleLe();
                break;

            case bc::RAVNO:
                handleEq();
                break;

            case bc::NE_RAVNO:
                handleNe();
                break;

            case bc::NE:
                handleNot();
                break;

            default:
                handleUnsupported(instr.op);
        }
        instructionPointer++;
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
        if (dataStack.empty()) {
            throw std::runtime_error("Stack underflow on STORE_VAR");
        }

        llvm::APInt value = dataStack.back();

        dataStack.pop_back();

        if (!functionStack.empty()) {
            functionStack.back()[instr.name] = value;
        } else {
            vars[instr.name] = value;
        }
    }



    void VirtualMachine::handleLoadVar(const bc::Instruction &instr) {
        if (!instr.has_name) {
            throw std::runtime_error("LOAD_VAR missing variable name");
        }

        if (!functionStack.empty() && functionStack.back().find(instr.name) != functionStack.back().end()) {
            dataStack.push_back(functionStack.back()[instr.name]);
        } else if (vars.find(instr.name) != vars.end()) {
            dataStack.push_back(vars[instr.name]);
        } else {
            throw std::runtime_error("Variable not found: " + instr.name);
        }
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
        dataStack.push_back(b - a);
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
        dataStack.push_back(b.sdiv(a));
    }

    void VirtualMachine::handleGt() {
        if (dataStack.size() < 2) {
            throw std::runtime_error("Stack underflow on GT");
        }
        llvm::APInt b = dataStack.back();
        dataStack.pop_back();
        llvm::APInt a = dataStack.back();
        dataStack.pop_back();
        a = (a.getLimitedValue() == 0) ? llvm::APInt(128, 0) : a ;
        b = (b.getLimitedValue() == 0) ? llvm::APInt(128, 0) : b ;
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

    void VirtualMachine::handleAlloc() {
        if (dataStack.empty()) {
            throw std::runtime_error("Stack underflow on Alloc");
        }
        auto allocSize = dataStack.back();
        dataStack.pop_back();
        if (!allocSize.isIntN(sizeof(size_t) * 8)) {
            throw std::runtime_error("ALLOC operand exceeds platform size limit");
        }

        void *allocatedMemory = GC_MALLOC(allocSize.getLimitedValue() * 16);
        if (!allocatedMemory) {
            throw std::runtime_error("Memory allocation failed");
        }

        llvm::APInt ptrValue(sizeof(uintptr_t) * 8, reinterpret_cast<uintptr_t>(allocatedMemory));
        dataStack.push_back(ptrValue);
    }

    void VirtualMachine::handleStoreInArray() {
        llvm::APInt arrayPtrAPInt = dataStack.back();
        dataStack.pop_back();

        llvm::APInt value = dataStack.back();
        dataStack.pop_back();

        llvm::APInt index = dataStack.back();
        dataStack.pop_back();

        llvm::APInt *arrayPtr = reinterpret_cast<llvm::APInt *>(arrayPtrAPInt.getLimitedValue());

        uint64_t indexValue = index.getLimitedValue();

        if (!arrayPtr) {
            throw std::runtime_error("Null pointer dereferenced");
        }

        llvm::APInt *targetCell = reinterpret_cast<llvm::APInt *>(&arrayPtr[indexValue]);
        *targetCell = value;
    }

    void VirtualMachine::handleLoadFromArray() {
        llvm::APInt arrayPtrAPInt = dataStack.back();
        dataStack.pop_back();

        llvm::APInt index = dataStack.back();
        dataStack.pop_back();

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

    void VirtualMachine::handleLoadPtr(const bc::Instruction &instr) {
        if (!instr.has_name) {
            throw std::runtime_error("LOAD_VAR missing variable name");
        }

        if (!functionStack.empty() && functionStack.back().find(instr.name) != functionStack.back().end()) {
            dataStack.push_back(functionStack.back()[instr.name]);
        } else if (vars.find(instr.name) != vars.end()) {
            dataStack.push_back(vars[instr.name]);
        } else {
            throw std::runtime_error("Variable not found: " + instr.name);
        }
    }


    void VirtualMachine::handleStorePtr(const bc::Instruction &instr) {
        if (!instr.has_name) {
            throw std::runtime_error("STORE_VAR missing variable name");
        }
        if (dataStack.empty()) {
            throw std::runtime_error("Stack underflow on STORE_VAR");
        }


        llvm::APInt value = dataStack.back();


        dataStack.pop_back();

        if (!functionStack.empty()) {
            functionStack.back()[instr.name] = value;
        } else {
            vars[instr.name] = value;
        }
    }

    void VirtualMachine::handleFuncBegin(const bc::Instruction& instr) {
        if (!instr.has_name) {
            throw std::runtime_error("FUNC_BEGIN missing function name");
        }

        if (functions.find(instr.name) != functions.end()) {
            throw std::runtime_error("FUNC_BEGIN A function with this name already exists: " + instr.name);
        }

        functions[instr.name] = {instructionPointer + 1, 0};
    }


    void VirtualMachine::handleFuncEnd() {
        if (callStack.empty()) {
            throw std::runtime_error("FUNC_END стек вызовов пуст");
        }

        if (functions.empty()) {
            throw std::runtime_error("FUNC_END call stack is empty");
        }

        std::string funcName = functions.begin()->first;
        functions[funcName].second = instructionPointer;

        instructionPointer = callStack.back();
        callStack.pop_back();
        functionStack.pop_back();
        isFunctionExec = false;
    }


    void VirtualMachine::handleReturn() {
        if (callStack.empty()) {
            throw std::runtime_error("RETURN empty call stack");
        }

        llvm::APInt returnValue = dataStack.empty() ? llvm::APInt(128, 0) : dataStack.back();
        if (!dataStack.empty()) {
            dataStack.pop_back();
        }

        instructionPointer = callStack.back() - 1;
        callStack.pop_back();

        if (!functionStack.empty()) {
            functionStack.pop_back();
        }

        dataStack.push_back(returnValue);
    }


    void VirtualMachine::handleCall(const bc::Instruction& instr) {
        if (!instr.has_name) {
            throw std::runtime_error("CALL missing function name");
        }

        if (functions.find(instr.name) == functions.end()) {
            throw std::runtime_error("CALL function not found: " + instr.name);
        }

        size_t numArgs = instr.operand.getLimitedValue();

        if (dataStack.size() < numArgs) {
            throw std::runtime_error("CALL not enough arguments for the function " + instr.name);
        }

        std::unordered_map<std::string, llvm::APInt> localVars;

        callStack.push_back(instructionPointer + 1);

        functionStack.push_back(localVars);

        auto [start, end] = functions[instr.name];
        instructionPointer = start;
        isFunctionExec = true;
    }

    void VirtualMachine::handleLabel(const bc::Instruction &instr, size_t &currentPointer) {
        labels.insert(std::make_pair(instr.operand.getLimitedValue(), currentPointer));
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