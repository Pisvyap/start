#include <iostream>
#include <fstream>
#include <iterator>
#include <typlypParser.h>

#include "antlr4-runtime.h"
#include "ast/ASTBuilder.h"
#include "ast/ASTNode.h"
#include "grammar/typlypLexer.h"

std::string readFile(const std::string& fileName) {
    const std::string path = "../scratches/" + fileName;

    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "File " << path << " does not exist" << std::endl;
        return std::string();
    }

    std::string contents(std::istreambuf_iterator<char>{file}, {});
    file.close();

    return contents;
}


int main() {
    const std::string input = readFile("test.typlyp");

    // Создание ANTLR потока
    antlr4::ANTLRInputStream inputStream(input);
    auto lexer = typlypLexer(&inputStream);
    antlr4::CommonTokenStream tokenStream(&lexer);
    auto parser = typlypParser(&tokenStream);

    // Дерево разбора
    auto tree = parser.program();

    // Строим AST
    ASTBuilder builder;
    try {
        auto ast = builder.visitProgram(tree);
        auto enter = std::any_cast<Ptr<ProgramNode>>(ast);
        enter->print(0);

        SemanticTable table;
        enter->semantic_check(table);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
