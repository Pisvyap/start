//
// Created by ladyp on 16.01.2025.
//

#include "bytecode.h"
#include "llvm/ADT/SmallString.h"

#include <iostream>

namespace bc {
    std::vector<Instruction> bytecode;
}

void bc::print_bytecode() {
    for (const auto& bc : bytecode) {
        std::cout << bc.op;
        if (bc.has_name)
            std::cout << ' ' << bc.name;

        if (bc.has_operand){
            llvm::SmallString<40> operandBuffer;
            bc.operand.toString(operandBuffer, 10, true);
            std::cout << ' ' << operandBuffer.c_str();
        }


        std::cout << '\n';
    }
}

std::ostream& bc::operator<<(std::ostream& os, const OP& op) {
    switch (op) {
        case PUSTAYA:
            os << "PASS";
            return os;
        case GRUZY_POSTOYANNUYU:
            os << "LOAD_CONST";
            return os;
        case GRUZY_PEREMENNUYU:
            os << "LOAD_VAR";
            return os;
        case HRANY_PEREMENNUYU:
            os << "STORE_VAR";
            return os;
        case ZOVY:
            os << "CALL";
            return os;
        case MISSIYA_NACHALO:
            os << "FUNC_BEGIN";
            return os;
        case MISSIYA_KONEC:
            os << "FUNC_END";
            return os;
        case VERNUT:
            os << "RETURN";
            return os;
        case DOBAV:
            os << "ADD";
            return os;
        case VICHTY:
            os << "SUB";
            return os;
        case UMNOZH:
            os << "MUL";
            return os;
        case DELY:
            os << "DIV";
            return os;
        case BOLSHE:
            os << "GT";
            return os;
        case BOLSHE_ILI_RAVNO:
            os << "GE";
            return os;
        case MENSHE:
            os << "LT";
            return os;
        case MENSHE_ILI_RAVNO:
            os << "LE";
           return os;
        case RAVNO:
            os << "EQ";
            return os;
        case NE_RAVNO:
            os << "NE";
           return os;
        case NE:
            os << "NOT";
            return os;
        case METKA:
            os << "LABEL";
            return os;
        case PRIGAY_ESLI_NEPRAVDA:
            os << "JUMP_IF_FALSE";
            return os;
        case PRIGAY:
            os << "JUMP";
            return os;
        case VIVEDY:
            os << "PRINT";
            return os;
        case VIDAY:
            os << "ALLOC";
            return os;
        case GRUZY_UKAZATEL:
            os << "LOAD_PTR";
            return os;
        case HRANY_UKAZATEL:
            os << "STORE_PTR";
            return os;
        case GRUZY_V_SGRUDU:
            os << "STORE_IN_ARRAY";
            return os;
        case GRUZY_IZ_SGRUDY:
            os << "LOAD_FROM_ARRAY";
            return os;
        default:
            throw std::invalid_argument("missing operator<< branch for OP");
    }
}

