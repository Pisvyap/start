cmake_minimum_required(VERSION 3.28.1)
project(typlyp VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(LLVM_ENABLE_PIC ON)

set(LLVM_DIR "${CMAKE_SOURCE_DIR}/llvm-project/lib/cmake/llvm")

find_package(LLVM REQUIRED CONFIG)
llvm_map_components_to_libnames(LLVM_LIBS support core irreader bitreader)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "LLVM include dir: ${LLVM_INCLUDE_DIRS}")
message(STATUS "LLVM libraries: ${LLVM_LIBRARY_DIRS}")

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
        ast/nodes/expressions/FunctionCallExpressionNode.h
        ast/nodes/expressions/BinaryOperationNode.h
        ast/nodes/expressions/UnaryOperationNode.h
        ast/nodes/statements/AssigmentStatementNode.h
        ast/nodes/expressions/LiteralNode.h
        ast/nodes/expressions/NumberLiteralNode.h
        ast/nodes/expressions/BoolLiteralNode.h
        ast/nodes/expressions/IdentifierNode.h
        ast/nodes/expressions/ArrayIndexExpressionNode.h
        ast/nodes/statements/VariableDecalrationNode.h
        ast/nodes/expressions/NewExpressionNode.h
        ast/nodes/statements/ArrayAssigmentNode.h
        ast/nodes/statements/ForStatementNode.h
        ast/semantics/SemanticTable.cpp
        ast/semantics/SemanticTable.h
        ast/CodeGeneration.cpp
)

add_subdirectory(
        antlr4-cpp-runtime
        llvm-project
)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug$<$<CONFIG:Debug>:>")
endif()

add_executable(
        typlyp
        main.cpp
        ${SOURCE_FILES}
)

target_link_libraries(
        typlyp
        PRIVATE
        antlr4_static
        ${LLVM_LIBS}
)

# Include directories
target_include_directories(typlyp PRIVATE
        ${LLVM_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-cpp-runtime/runtime/src
        ${CMAKE_CURRENT_SOURCE_DIR}/grammar
)