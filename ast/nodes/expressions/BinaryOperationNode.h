#pragma once

#include "../../ASTNode.h"
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
private:
    std::string print_enum(BinaryOperationType op) {
        switch (op) {
            case BinaryOperationType::Add:
                return "+";
            case BinaryOperationType::Sub:
                return "-";
            case BinaryOperationType::Mul:
                return "*";
            case BinaryOperationType::Div:
                return "/";
            case BinaryOperationType::Mod:
                return "%";
            case BinaryOperationType::LT:
                return "<";
            case BinaryOperationType::LE:
                return "<=";
            case BinaryOperationType::GT:
                return ">";
            case BinaryOperationType::GE:
                return ">=";
            case BinaryOperationType::EQ:
                return "==";
            case BinaryOperationType::NE:
                return "!=";
        }
    }
};