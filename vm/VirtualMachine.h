#include <unordered_map>
#include <vector>
#include <string>
#include "llvm/ADT/APInt.h"
#include "gc.h"
#include "../bytecode/bytecode.h"

namespace vm {

    struct VirtualMachine {
        std::vector<llvm::APInt> dataStack;               // Стек данных
        std::unordered_map<std::string, llvm::APInt> vars; // Переменные
        size_t instructionPointer = 0;                // Указатель на текущую инструкцию

        VirtualMachine();

        // Выполнение байткода
        void execute(const std::vector<bc::Instruction>& bytecode);

        void handleLoadConst(const bc::Instruction& instr);
        void handleStoreVar(const bc::Instruction& instr);
        void handleLoadVar(const bc::Instruction& instr);
        void handleAdd();
        void handlePrint();
        void handleAlloc(const bc::Instruction& instr);
        void handleStoreInArray();
        void handleLoadFromArray();
        void handlePass();
        void handleLoadPtr(const bc::Instruction &instr);
        void handleStorePtr(const bc::Instruction &instr);
        void handleFuncBegin();
        void handleFuncEnd();
        void handleReturn();
        void handleLabel();
        void handleJumpIfFalse();
        void handleJump();
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

