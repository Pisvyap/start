#include <unordered_map>
#include <vector>
#include <string>
#include "llvm/ADT/APInt.h"
#include "gc.h"
#include "../bytecode/bytecode.h"
#include <map>

namespace vm {

    struct VirtualMachine {
        std::vector<llvm::APInt> dataStack;               // Стек данных
        std::unordered_map<std::string, llvm::APInt> vars; // Переменные
        std::map<uint64_t, size_t> labels;           //Якори
        std::vector<size_t> callStack;
        std::vector<std::unordered_map<std::string, llvm::APInt>> functionStack;
        std::unordered_map<std::string, std::pair<size_t, size_t>> functions; // Таблица функций
        size_t instructionPointer = 0;                // Указатель на текущую инструкцию
        bool isFunctionExec = false;
        int test = 0;

        VirtualMachine();

        // Выполнение байткода
        void execute(const std::vector<bc::Instruction>& bytecode);
        void executeInstruction(const bc::Instruction instr);

        void handleLoadConst(const bc::Instruction& instr);
        void handleStoreVar(const bc::Instruction& instr);
        void handleLoadVar(const bc::Instruction& instr);
        void handleAdd();
        void handlePrint();
        void handleAlloc();
        void handleStoreInArray();
        void handleLoadFromArray();
        void handlePass();
        void handleLoadPtr(const bc::Instruction &instr);
        void handleStorePtr(const bc::Instruction &instr);
        void handleFuncBegin(const bc::Instruction &instr);
        void handleFuncEnd();
        void handleReturn();
        void handleCall(const bc::Instruction &instr);
        void handleLabel(const bc::Instruction &instr, size_t &currentPointer);
        void handleJumpIfFalse(const bc::Instruction &instr, size_t &currentPointer);
        void handleJump(const bc::Instruction &instr, size_t &currentPointer);
        void handleGt();
        void handleGe();
        void handleLt();
        void handleLe();
        void handleEq();
        void handleNe();
        void handleSub();
        void handleMul();
        void handleDiv();
        void handleNot();

        void handleUnsupported(bc::OP op);
    };


}

