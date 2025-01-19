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
            if (instr.op == bc::FUNC_BEGIN) {
                handleFuncBegin(instr);
                funcStart = i;  // Запоминаем начало функции
            } else if (instr.op == bc::FUNC_END) {
                if (funcStart == -1) {
                    throw std::runtime_error("FUNC_END without matching FUNC_BEGIN");
                }
                // Сохраняем диапазон инструкции функции
                functions[bytecode[funcStart].name] = {funcStart, i};
                funcStart = -1;
            } else if ( instr.op == bc::LABEL) {
                // Обрабатываем метки вне функции
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
            // Если инструкция находится в диапазоне определённой функции — пропускаем
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
                continue; // Пропускаем исполнение этой команды
            }

            // Выполняем текущую инструкцию
            executeInstruction(instr);
        }

    }

    void VirtualMachine::executeInstruction(const bc::Instruction instr)  {
//        if (test < 100) {
//            std::cout << "instr: " << instr.op << std::endl;
//            test++;
//        }
        //std::cout << instr.op << std::endl;
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
                handleAlloc();
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
                handleFuncBegin(instr);
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
            functionStack.back()[instr.name] = value; // Сохраняем в локальном контексте
        } else {
            vars[instr.name] = value; // Сохраняем в глобальных переменных
        }
    }



    void VirtualMachine::handleLoadVar(const bc::Instruction &instr) {
        if (!instr.has_name) {
            throw std::runtime_error("LOAD_VAR missing variable name");
        }

        if (!functionStack.empty() && functionStack.back().find(instr.name) != functionStack.back().end()) {
            dataStack.push_back(functionStack.back()[instr.name]); // Загружаем из локального контекста
        } else if (vars.find(instr.name) != vars.end()) {
            dataStack.push_back(vars[instr.name]); // Загружаем из глобальных переменных
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

        // Выделяем память через GC_MALLOC
        void *allocatedMemory = GC_MALLOC(allocSize.getLimitedValue() * 16);
        if (!allocatedMemory) {
            throw std::runtime_error("Memory allocation failed");
        }

        // Сохраняем указатель как llvm::APInt в стек
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

        // Преобразуем указатель в реальный указатель на массив
        llvm::APInt *arrayPtr = reinterpret_cast<llvm::APInt *>(arrayPtrAPInt.getLimitedValue());

        uint64_t indexValue = index.getLimitedValue();

        if (!arrayPtr) {
            throw std::runtime_error("Null pointer dereferenced");
        }

        // Сохраняем значение в массиве
        llvm::APInt *targetCell = reinterpret_cast<llvm::APInt *>(&arrayPtr[indexValue]);
        *targetCell = value;
    }

    void VirtualMachine::handleLoadFromArray() {
        llvm::APInt arrayPtrAPInt = dataStack.back();
        dataStack.pop_back();

        llvm::APInt index = dataStack.back();
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

    void VirtualMachine::handleLoadPtr(const bc::Instruction &instr) {
        if (!instr.has_name) {
            throw std::runtime_error("LOAD_VAR missing variable name");
        }

        if (!functionStack.empty() && functionStack.back().find(instr.name) != functionStack.back().end()) {
            dataStack.push_back(functionStack.back()[instr.name]); // Загружаем из локального контекста
        } else if (vars.find(instr.name) != vars.end()) {
            dataStack.push_back(vars[instr.name]); // Загружаем из глобальных переменных
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
            functionStack.back()[instr.name] = value; // Сохраняем в локальном контексте
        } else {
            vars[instr.name] = value; // Сохраняем в глобальных переменных
        }
    }

    void VirtualMachine::handleFuncBegin(const bc::Instruction& instr) {
        if (!instr.has_name) {
            throw std::runtime_error("FUNC_BEGIN missing function name");
        }

        // Проверяем, что функция еще не существует в таблице
        if (functions.find(instr.name) != functions.end()) {
            throw std::runtime_error("FUNC_BEGIN A function with this name already exists: " + instr.name);
        }

        // Сохраняем начало функции в таблице
        functions[instr.name] = {instructionPointer + 1, 0};  // Будем обновлять конец функции позже
    }


    void VirtualMachine::handleFuncEnd() {
        if (callStack.empty()) {
            throw std::runtime_error("FUNC_END стек вызовов пуст");
        }

        // Обновляем конец функции в таблице функций
        if (functions.empty()) {
            throw std::runtime_error("FUNC_END call stack is empty");
        }

        // Получаем имя функции, чтобы обновить диапазон
        std::string funcName = functions.begin()->first;
        functions[funcName].second = instructionPointer;  // Устанавливаем конец функции

        // Удаляем локальный контекст и восстанавливаем указатель на следующую инструкцию
        instructionPointer = callStack.back();
        callStack.pop_back();
        functionStack.pop_back();
        isFunctionExec = false;  // Функция завершена
    }


    void VirtualMachine::handleReturn() {
        if (callStack.empty()) {
            throw std::runtime_error("RETURN empty call stack");
        }

        // Получаем возвращаемое значение (или 0, если ничего нет в стеке)
        llvm::APInt returnValue = dataStack.empty() ? llvm::APInt(64, 0) : dataStack.back();
        if (!dataStack.empty()) {
            dataStack.pop_back();
        }

        // Восстанавливаем указатель на инструкцию возврата
        instructionPointer = callStack.back()-1;
        callStack.pop_back();

        // Очищаем локальный контекст
        if (!functionStack.empty()) {
            functionStack.pop_back();
        }

        // Возвращаем результат в стек
        dataStack.push_back(returnValue);
    }


    void VirtualMachine::handleCall(const bc::Instruction& instr) {
        if (!instr.has_name) {
            throw std::runtime_error("CALL missing function name");
        }


        // Проверка наличия функции в таблице
        if (functions.find(instr.name) == functions.end()) {
            throw std::runtime_error("CALL function not found: " + instr.name);
        }

        size_t numArgs = instr.operand.getLimitedValue();

        // Проверяем, что в стеке есть достаточно аргументов
        if (dataStack.size() < numArgs) {
            throw std::runtime_error("CALL not enough arguments for the function " + instr.name);
        }

        // Передаем аргументы в локальные переменные функции
        std::unordered_map<std::string, llvm::APInt> localVars;

        // Сохраняем текущую позицию (для возврата после выполнения функции)
        callStack.push_back(instructionPointer + 1);  // Сохраняем позицию после CALL

        // Создаем новый локальный контекст для функции
        functionStack.push_back(localVars);

        // Переходим к началу функции
        auto [start, end] = functions[instr.name];
        instructionPointer = start;  // Пропускаем FUNC_BEGIN
        isFunctionExec = true;  // Функция теперь выполняется
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