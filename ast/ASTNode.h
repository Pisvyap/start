#pragma once

#include <iostream>
#include <memory>
#include <string>


class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void print(const int indent) {
        for (int i = 0; i < indent; i++)
            std::cout << '\t';
    }
};

template<typename T>
using Ptr = std::shared_ptr<T>;
