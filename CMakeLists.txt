cmake_minimum_required(VERSION 3.30)
project(typlyp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
        SOURCE_FILES
        grammar/typlypBaseListener.cpp
        grammar/typlypBaseVisitor.cpp
        grammar/typlypLexer.cpp
        grammar/typlypListener.cpp
        grammar/typlypParser.cpp
        grammar/typlypVisitor.cpp

        ast/ASTNode.cpp
        ast/ASTBuilder.cpp
        ast/nodes/CodeBlockNode.h
        ast/nodes/expressions/ExpressionNode.h
        ast/nodes/ExternalFunctionNode.h
        ast/nodes/FunctionNode.h
        ast/nodes/ParameterNode.h
        ast/nodes/ProgramNode.h
        ast/nodes/statements/IfStatementNode.h
        ast/nodes/statements/ReturnStatementNode.h
        ast/nodes/statements/StatementNode.h
        ast/nodes/statements/WhileStatementNode.h
        ast/nodes/statements/ExpressionStatementNode.h
        ast/nodes/expressions/FunctionCallExpression.h
        ast/nodes/expressions/BinaryOperationNode.h
        ast/nodes/expressions/UnaryOperationNode.h
        ast/nodes/statements/AssigmentStatementNode.h
        ast/nodes/expressions/LiteralNode.h
        ast/nodes/expressions/NumberLiteralNode.h
        ast/nodes/expressions/BoolLiteralNode.h
        ast/nodes/expressions/IdentifierNode.h
)

add_subdirectory(antlr4-cpp-runtime)

add_executable(
        typlyp
        main.cpp
        ${SOURCE_FILES}
)

target_link_libraries(
        typlyp
        PRIVATE
        antlr4_static
)

# Include directories
target_include_directories(typlyp PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-cpp-runtime/runtime/src
        ${CMAKE_CURRENT_SOURCE_DIR}/grammar
)