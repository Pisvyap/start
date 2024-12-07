#pragma once

#include <memory>
#include <vector>
#include <string>


template<typename T = void>
class ASTNode {
public:
    virtual ~ASTNode() = default;

    using Ptr = std::shared_ptr<T>;
};

template<>
class ASTNode<void> {
    public:
    virtual ~ASTNode() = default;

    using Ptr = std::shared_ptr<ASTNode>;
};
