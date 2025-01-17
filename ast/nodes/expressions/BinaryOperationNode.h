#pragma once

#include "../../ASTNode.h"
#include "../../utils/utils.h"
#include "ExpressionNode.h"

class BinaryOperationNode : public ExpressionNode {
public:
    enum BinaryOperationType {
        Add, Sub, Mul, Div, Mod, LT, LE, GT, GE, EQ, NE
    };

    BinaryOperationType operation;
    Ptr<ExpressionNode> left;
    Ptr<ExpressionNode> right;

    void print(const int indent) override {
        left->print(indent); std::cout << ' ' << print_enum(operation) << ' '; right->print(indent);
    }

    void semantic_check(SemanticTable& table) override {
        left->semantic_check(table);
        right->semantic_check(table);
        if (left->type != right->type)
            throw std::runtime_error("Can't perform binary operation between types "
                + std::to_string(left->type.type) + " and " + std::to_string(right->type.type));

        switch (operation) {
            case Add:
            case Sub:
            case Mul:
            case Div:
            case Mod:
            case LT:
            case LE:
            case GT:
            case GE:
                if (left->type != INT)
                    throw std::runtime_error("Arithmetic operations require 'chislo' type.");
                break;
            default:
                break;
        }

        this->type = get_type();
    }

    void generate_bytecode() override {
        // Тут сперва нужно положить оба операнда на стек
        // Сначала кладем ПРАВЫЙ операнд (если что поменять, хз как удобно потом будет)
        right->generate_bytecode();
        left->generate_bytecode();

        // Теперь добавляем операцию
        switch (operation) {
            case Add:
                bc::bytecode.emplace_back(bc::OP::ADD);
                return;
            case Sub:
                bc::bytecode.emplace_back(bc::OP::SUB);
                return;
            case Mul:
                bc::bytecode.emplace_back(bc::OP::MUL);
                return;
            case Div:
                bc::bytecode.emplace_back(bc::OP::DIV);
                return;
            case LT:
                bc::bytecode.emplace_back(bc::OP::LT);
                return;
            case LE:
                bc::bytecode.emplace_back(bc::OP::LE);
                return;
            case GT:
                bc::bytecode.emplace_back(bc::OP::GT);
                return;
            case GE:
                bc::bytecode.emplace_back(bc::OP::GE);
                return;
            case EQ:
                bc::bytecode.emplace_back(bc::OP::EQ);
                return;
            case NE:
                bc::bytecode.emplace_back(bc::OP::NE);
                return;
            default:
                throw std::runtime_error("AST and Bytecode binary operators mismatch");
        }
    }

    llvm::Value *Codegen() override;
private:
    ScalarType get_type() const {
        switch (operation) {
            case Add:
            case Sub:
            case Mul:
            case Div:
            case Mod:
                return INT;
            case LT:
            case LE:
            case GT:
            case GE:
            case EQ:
            case NE:
                return BOOL;
        }

        throw std::runtime_error("Can't define return type");
    }

    std::string print_enum(BinaryOperationType op) {
        switch (op) {
            case Add:
                return "+";
            case Sub:
                return "-";
            case Mul:
                return "*";
            case Div:
                return "/";
            case Mod:
                return "%";
            case LT:
                return "<";
            case LE:
                return "<=";
            case GT:
                return ">";
            case GE:
                return ">=";
            case EQ:
                return "==";
            case NE:
                return "!=";
        }
    }
};
