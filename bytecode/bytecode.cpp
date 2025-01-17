//
// Created by ladyp on 16.01.2025.
//

#include "bytecode.h"

#include <iostream>

namespace bc {
    std::vector<Instruction> bytecode;
}

void bc::print_bytecode() {
    for (const auto& bc : bytecode) {
        std::cout << bc.op;
        if (bc.has_name)
            std::cout << ' ' << bc.name;

        if (bc.has_operand)
            std::cout << ' ' << bc.operand;

        std::cout << '\n';
    }
}

std::ostream& bc::operator<<(std::ostream& os, const OP& op) {
    switch (op) {
        case PASS:
            os << "PASS";
            return os;
        case LOAD_CONST:
            os << "LOAD_CONST";
            return os;
        case LOAD_VAR:
            os << "LOAD_VAR";
            return os;
        case STORE_VAR:
            os << "STORE_VAR";
            return os;
        case CALL:
            os << "CALL";
            return os;
        case FUNC_BEGIN:
            os << "FUNC_BEGIN";
            return os;
        case FUNC_END:
            os << "FUNC_END";
            return os;
        case RETURN:
            os << "RETURN";
            return os;
        case ADD:
            os << "ADD";
            return os;
        case SUB:
            os << "SUB";
            return os;
        case MUL:
            os << "MUL";
            return os;
        case DIV:
            os << "DIV";
            return os;
        case GT:
            os << "GT";
            return os;
        case GE:
            os << "GE";
            return os;
        case LT:
            os << "LT";
            return os;
        case LE:
            os << "LE";
           return os;
        case EQ:
            os << "EQ";
            return os;
        case NE:
            os << "NE";
           return os;
        case NOT:
            os << "NOT";
            return os;
        case LABEL:
            os << "LABEL";
            return os;
        case JUMP_IF_FALSE:
            os << "JUMP_IF_FALSE";
            return os;
        case JUMP:
            os << "JUMP";
            return os;
        case PRINT:
            os << "PRINT";
            return os;
        case ALLOC:
            os << "ALLOC";
            return os;
        case LOAD_PTR:
            os << "LOAD_PTR";
            return os;
        case STORE_PTR:
            os << "STORE_PTR";
            return os;
        case STORE_IN_ARRAY:
            os << "STORE_IN_ARRAY";
            return os;
        case LOAD_FROM_ARRAY:
            os << "LOAD_FROM_ARRAY";
            return os;
        default:
            throw std::invalid_argument("missing operator<< branch for OP");
    }
}

