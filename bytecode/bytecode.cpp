//
// Created by ladyp on 16.01.2025.
//

#include "bytecode.h"

#include <iostream>

void bc::print_bytecode() {
    for (const auto& bc : bc::bytecode) {
        std::cout << bc.op;
        if (bc.has_operand)
            std::cout << ' ' << bc.operand;
        else
            std::cout << ' ' << bc.name;
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
        case ADD:
            os << "ADD";
            return os;
        default:
            throw std::invalid_argument("missing operator<< branch for OP");
    }
}

