#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "grammar/typlypLexer.h"

int main() {
    try {
        // Создаём входной поток из файла или строки
        std::ifstream stream;
        stream.open("input.txt");
        antlr4::ANTLRInputStream input(stream);

        // // Создаём лексер
        typlypLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);


        // Если нужно использовать visitor:
        // typlypVisitor visitor;
        // visitor.visit(tree);

        std::cout << "Parsing completed successfully!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
