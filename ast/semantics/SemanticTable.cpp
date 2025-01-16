//
// Created by ladyp on 17.12.2024.
//

#include "SemanticTable.h"

bool Type::operator==(const Type& other) const {
    return is_void
        ? other.is_void
        : type == other.type && is_array == other.is_array;
}

bool Type::operator!=(const Type& other) const {
    return !(*this == other);
}

