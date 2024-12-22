#pragma once
#include <list>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

enum Type {
    INT,
    BOOL,
    INT_ARRAY,
    BOOL_ARRAY
};

struct TypeStruct {
    Type type;
    int array_size = 0;
    TypeStruct() { }
    TypeStruct(Type type) : type(type) { }
    TypeStruct(Type type, int size) : type(type), array_size(size) {}
    bool is_array() const {
        return type == INT_ARRAY || type == BOOL_ARRAY;
    }

    bool operator==(const TypeStruct& other) const {
        return type == other.type && array_size == other.array_size;
    }

    bool operator!=(const TypeStruct& other) const {
        return !(*this == other);
    }
};

static TypeStruct map_type(const std::string& name) {
    if (name.substr(0, 6) == "chislo") {
        if (name == "chislo")
            return TypeStruct(INT);

        size_t openBracket = name.find('[');
        size_t closeBracket = name.find(']');
        std::string numberStr = name.substr(openBracket + 1, closeBracket - openBracket - 1);
        return TypeStruct(INT_ARRAY, std::stoi(numberStr));
    }

    if (name.substr(0, 6) == "logika") {
        if (name == "logika")
            return TypeStruct(BOOL);

        size_t openBracket = name.find('[');
        size_t closeBracket = name.find(']');
        std::string numberStr = name.substr(openBracket + 1, closeBracket - openBracket - 1);
        return TypeStruct(INT_ARRAY, std::stoi(numberStr));
    }

    throw std::runtime_error("Unsupported type " + name);
}

static std::string map_type(TypeStruct type) {
    switch (type.type) {
        case INT: return "int";
        case BOOL: return "bool";
        case INT_ARRAY: return "int[" + std::to_string(type.array_size) + "]";
        case BOOL_ARRAY: return "bool[" + std::to_string(type.array_size) + "]";
        default: throw std::runtime_error("Unsupported type " + std::to_string(type.type));
    }
}

// Это типа описание идентификатора
struct Symbol {
    TypeStruct type;
    bool isFunction;
    std::vector<TypeStruct> paramTypes; // Типы параметров, если функция

    Symbol() { }

    Symbol(TypeStruct type, bool isFunction) : type(type), isFunction(isFunction) {}

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

