#pragma once

#include "semantics/SemanticTable.h"

#include <iostream>
#include <memory>


class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void print(const int indent) {
        for (int i = 0; i < indent; i++)
            std::cout << '\t';
    }

    virtual void semantic_check(SemanticTable& table) { }
};

template<typename T>
using Ptr = std::shared_ptr<T>;
