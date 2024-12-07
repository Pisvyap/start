#pragma once

#include <memory>
#include <string>


class ASTNode {
public:
    virtual ~ASTNode() = default;
};

template<typename T>
using Ptr = std::shared_ptr<T>;
