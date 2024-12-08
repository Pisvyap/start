#pragma once
#include <vector>

#include "ExpressionNode.h"

class FunctionCallExpression : public ExpressionNode {
public:
    bool isExternal = false;
    std::string name;
    std::vector<Ptr<ExpressionNode>> arguments;
    void print(const int indent) override {
        if (isExternal)
            std::cout << "External ";

        std::cout << "FunctionCall " << name << "(";
        for (int i = 0; i < arguments.size(); i++) {
            arguments[i]->print(indent);
            std::cout << ", ";
        }

        std::cout << ")";
    }
};