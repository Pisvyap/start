#include <unordered_map>
#include <vector>
#include <string>
#include "gc.h"
#include "../bytecode/bytecode.h"

namespace vm {

    struct VirtualMachine {
        std::vector<uint64_t> dataStack;               // Стек данных
        std::unordered_map<std::string, uint64_t> vars; // Переменные
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
        void handleLoadPtr();
        void handleStorePtr();
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
        void handleNot();

        void handleUnsupported(bc::OP op)
    };


}

