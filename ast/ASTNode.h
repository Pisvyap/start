#pragma once

#include "../bytecode/bytecode.h"
#include "semantics/SemanticTable.h"
#include <llvm/IR/Value.h>
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
    virtual llvm::Value* Codegen() { return nullptr; }
    virtual void generate_bytecode() { }
};

template<typename T>
using Ptr = std::shared_ptr<T>;
