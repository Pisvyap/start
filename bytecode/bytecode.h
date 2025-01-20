#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "llvm/ADT/APInt.h"

namespace bc {
    enum OP {
        PUSTAYA,                    // Пустая операция
        GRUZY_POSTOYANNUYU,         // Запись константы в верхушку стека, я думаю константа = беззнаковое число
        GRUZY_PEREMENNUYU,          // Запись заранее сохраненной переменной в верхушку стека
        HRANY_PEREMENNUYU,          // Запись верхнего элемента стека в переменную (и удаление со стека)
        GRUZY_UKAZATEL,             // Запись заранее сохраненного указателя в верхушку стека
        HRANY_UKAZATEL,             // Запись верхнего элемента стека (указателя) в переменную (и удаление со стека)
        GRUZY_V_SGRUDU,             // Запись в ячейку массива
        GRUZY_IZ_SGRUDY,            // Запись в стек из ячейки массива
        ZOVY,                       // Вызов функции, предполагаем, что аргументы уже на стеке подготовлены. Результат также помещается на стек
        MISSIYA_NACHALO,            // Обозначение, что дальше идет блок кода функции
        MISSIYA_KONEC,              // Обозначение конца блока функции
        VERNUT,                     // Возвращение верхнего элемента стека
        METKA,                      // Установление метки в коде. Для ветвлений
        VIVEDY,                     // Выводит верхний элемент стека (и удаляет его со стека)

        // Бинарные операции. Берутся два верхних элемента стеки (удаляются). Результат помещается на верхушку стека
        DOBAV,
        VICHTY,
        UMNOZH,
        DELY,
        BOLSHE,
        BOLSHE_ILI_RAVNO,
        MENSHE,
        MENSHE_ILI_RAVNO,
        RAVNO,
        NE_RAVNO,

        // Унарные операции(-ия). Берется верхний элемент. Результат помещается на верхушку стека
        NE,

        // Переходы (им передаются имена меток)
        PRIGAY_ESLI_NEPRAVDA,
        PRIGAY,

        // Все что связано с массивами
        VIDAY
    };

    // Для нормального вывода
    std::ostream& operator<<(std::ostream& os, const OP& op);

    // Инструкция байткода
    struct Instruction {
        OP op;
        llvm::APInt operand; // возможное число
        std::string name; // возможное имя
        bool has_operand;
        bool has_name;

        Instruction()
                    : op(PUSTAYA), operand(128,0), has_operand(false), has_name(false) {}

        explicit Instruction(const OP op)
                    : op(op), operand(128, 0), has_operand(false), has_name(false) {}

        Instruction(const OP op, const llvm::APInt& operand)
                    : op(op), operand(operand), has_operand(true), has_name(false) {}

        Instruction(const OP op, const std::string &name)
                    : op(op), operand(128, 0), name(name), has_operand(false), has_name(true) {}

        Instruction(const OP op, const std::string& name, const llvm::APInt& operand)
                    : op(op), operand(operand), name(name), has_operand(true), has_name(true) {}
    };

    // Здесь все инструкции, глобальная переменная
    extern std::vector<Instruction> bytecode;
    inline int LABEL_COUNT = 1;

    // Вывод байткода в консоль (или куда-то в другое место)
    void print_bytecode();
}


