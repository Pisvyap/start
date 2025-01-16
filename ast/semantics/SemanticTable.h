#pragma once
#include <list>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

enum ScalarType {
    INT,
    BOOL,
};

struct Type {
    ScalarType type;
    bool is_void;
    bool is_array;
    int array_size;
    Type() { }
    Type(bool is_void) : is_void(is_void), is_array(false), array_size(0) { }
    Type(ScalarType type) : type(type), is_array(false), array_size(0), is_void(false) { }
    Type(ScalarType type, bool is_array) : type(type), is_array(is_array), array_size(0), is_void(false) { }
    Type(ScalarType type, bool is_array, int size) : type(type), is_array(is_array), array_size(size), is_void(false) { }

    bool operator==(const Type& other) const;
    bool operator!=(const Type& other) const;
};

static Type map_type(const std::string& name, bool is_array) {
    if (name == "chislo")
        return Type(INT, is_array);
    if (name == "logika")
        return Type(BOOL, is_array);
    if (name == "nebytie")
        return Type(true);
    throw std::runtime_error("Unknown type: " + name);
}

static Type map_type(const std::string& name) {
    if (name.substr(0, 6) == "chislo") {
        if (name == "chislo")
            return Type(INT);

        size_t openBracket = name.find('<');
        size_t closeBracket = name.find('>');
        std::string numberStr = name.substr(openBracket + 1, closeBracket - openBracket - 1);
        try {
            int number = std::stoi(numberStr);
            return Type(INT, true, number);
        } catch (const std::invalid_argument& e) {
            return Type(INT, true);
        }
    }

    if (name.substr(0, 6) == "logika") {
        if (name == "logika")
            return Type(BOOL);

        size_t openBracket = name.find('<');
        size_t closeBracket = name.find('>');
        std::string numberStr = name.substr(openBracket + 1, closeBracket - openBracket - 1);
        try {
            int number = std::stoi(numberStr);
            return Type(BOOL, true, number);
        } catch (const std::invalid_argument& e) {
            return Type(BOOL, true);
        }
    }

    if (name == "nebytie") {
        return Type(true);
    }

    throw std::runtime_error("Unsupported type " + name);
}

static std::string to_string(const ScalarType& type) {
    switch (type) {
        case INT: return "int";
        case BOOL: return "bool";
        default: return "null";
    }
}

static std::string to_string(Type type) {
    switch (type.type) {
        case INT:
            if (!type.is_array)
                return "int";
            return "int[" + (type.array_size == 0 ? "" : std::to_string(type.array_size)) + "]";
        case BOOL:
            if (!type.is_array)
                return "bool";
            return "bool[" + (type.array_size == 0 ? "" : std::to_string(type.array_size)) + "]";
        default:
            if (type.is_void)
                return "void";
            throw std::runtime_error("Unsupported type (to_string) " + to_string(type.type));
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



