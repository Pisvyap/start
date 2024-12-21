#pragma once
#include <list>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

enum Type { // TODO возможно нужна поддержка для VOID так как внешние функции могут его возвращать
    INT,
    BOOL,
    INT_ARRAY,
    BOOL_ARRAY
};

static Type map_type(const std::string& name) {
    if (name == "chislo")
        return INT;
    if (name == "logika")
        return BOOL;
    if (name == "chislo[]")
        return INT_ARRAY;
    if (name == "logika[]")
        return BOOL_ARRAY;

    throw std::runtime_error("Unsupported type " + name);
}

static std::string map_type(Type type) {
    switch (type) {
        case INT: return "int";
        case BOOL: return "bool";
        case INT_ARRAY: return "int[]";
        case BOOL_ARRAY: return "bool[]";
        default: throw std::runtime_error("Unsupported type " + std::to_string(type));
    }
}

// Это типа описание идентификатора
struct Symbol {
    Type type;
    bool isFunction;
    std::vector<Type> paramTypes; // Типы параметров, если функция

    Symbol() { }

    Symbol(Type type, bool isFunction) : type(type), isFunction(isFunction) {}

    Symbol(const Symbol& symbol) {
        type = symbol.type;
        isFunction = symbol.isFunction;
        paramTypes = std::vector(symbol.paramTypes);
    }
};

class SemanticTable {
private:
    std::list<std::unordered_map<std::string, Symbol>> scopes;
public:
    void enterScope() {
        scopes.push_back({});
    }

    void leaveScope() {
        scopes.pop_back();
    }

    void addSymbol(const std::string& name, const Symbol& symbol) {
        if (scopes.empty())
            enterScope();

        scopes.back()[name] = symbol;
    }

    Symbol* lookup(const std::string& name) {
        for (auto it = scopes.rbegin(); it != scopes.rend(); ++it)
            if (it->count(name))
                return &it->at(name);

        return nullptr;
    }
};

