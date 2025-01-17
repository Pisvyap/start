#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace bc {
    enum OP {
        PASS,             // Пустая операция
        LOAD_CONST,       // Запись константы в верхушку стека, я думаю константа = беззнаковое число
        LOAD_VAR,         // Запись заранее сохраненной переменной в верхушку стека
        STORE_VAR,        // Запись верхнего элемента стека в переменную (и удаление со стека)
        LOAD_PTR,         // Запись заранее сохраненного указателя в верхушку стека
        STORE_PTR,        // Запись верхнего элемента стека (указателя) в переменную (и удаление со стека)
        STORE_IN_ARRAY,   // Запись в ячейку массива
        LOAD_FROM_ARRAY,  //
        CALL,             // Вызов функции, предполагаем, что аргументы уже на стеке подготовлены. Результат также помещается на стек
        FUNC_BEGIN,       // Обозначение, что дальше идет блок кода функции
        FUNC_END,         // Обозначение конца блока функции
        RETURN,           // Возвращение верхнего элемента стека
        LABEL,            // Установление метки в коде. Для ветвлений
        PRINT,            // Выводит верхний элемент стека (и удаляет его со стека)

        // Бинарные операции. Берутся два верхних элемента стеки (удаляются). Результат помещается на верхушку стека
        ADD,
        SUB,
        MUL,
        DIV,
        GT,
        GE,
        LT,
        LE,
        EQ,
        NE,

        // Унарные операции(-ия). Берется верхний элемент. Результат помещается на верхушку стека
        NOT,

        // Переходы (им передаются имена меток)
        JUMP_IF_FALSE,
        JUMP,

        // Все что связано с массивами
        ALLOC
    };

    // Для нормального вывода
    std::ostream& operator<<(std::ostream& os, const OP& op);

    // Инструкция байткода, например
    // LOAD_CONST 42
    // LOAD_VAR x
    // ADD
    struct Instruction {
        OP op;
        uint64_t operand; // возможное число
        std::string name; // возможное имя
        bool has_operand;
        bool has_name;

        Instruction()
                    : op(PASS), operand(0), has_operand(false), has_name(false) {}

        explicit Instruction(const OP op)
                    : op(op), operand(0), has_operand(false), has_name(false) {}

        Instruction(const OP op, const uint64_t operand)
                    : op(op), operand(operand), has_operand(true), has_name(false) {}

        Instruction(const OP op, const std::string &name)
                    : op(op), operand(0), name(name), has_operand(false), has_name(true) {}

        Instruction(const OP op, const std::string& name, const uint64_t operand)
                    : op(op), operand(operand), name(name), has_operand(true), has_name(true) {}
    };

    // Здесь все инструкции, глобальная переменная
    extern std::vector<Instruction> bytecode;
    inline int LABEL_COUNT = 1;

    // Вывод байткода в консоль (или куда-то в другое место)
    void print_bytecode();
}


