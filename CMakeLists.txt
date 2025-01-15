cmake_minimum_required(VERSION 3.23)
project(typlyp VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(LLVM_DIR "${CMAKE_SOURCE_DIR}/llvm-project/lib/cmake/llvm") #тут у меня путь другой, специально не меняю общей ветке
set(BDWGC_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/bdwgc/zig-out/include")
set(BDWGC_LIB_DIR "${CMAKE_SOURCE_DIR}/bdwgc/zig-out/lib")

include_directories(${BDWGC_INCLUDE_DIR})
link_directories(${BDWGC_LIB_DIR})

find_library(BDWGC_LIBS gc HINTS ${BDWGC_LIB_DIR} REQUIRED)

find_package(LLVM REQUIRED CONFIG)
llvm_map_components_to_libnames(
        LLVM_LIBS
        support
        core
        irreader
        bitreader
        x86codegen
        x86asmparser
        executionengine
        orcjit
)

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
        utils/utils.h
        ast/nodes/statements/PrintStatementNode.h
)

if(MSVC)
    # Использование /MD (динамическая библиотека времени выполнения)
    set(CMAKE_C_FLAGS_RELEASE "/MD")
    set(CMAKE_CXX_FLAGS_RELEASE "/MD")
    set(CMAKE_C_FLAGS_DEBUG "/MDd")
    set(CMAKE_CXX_FLAGS_DEBUG "/MDd")
endif()

message(STATUS "ANTLR4 Runtime Library Path: ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/libs/antlr4_runtime.lib")
message(STATUS "ANTLR4 Include Path: ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/include")

add_executable(
        typlyp
        main.cpp
        ${SOURCE_FILES}
)

link_directories(${LLVM_LIBRARY_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/libs)

target_link_libraries(
        typlyp
        PRIVATE
        ${LLVM_LIBS}
        ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/libs/antlr4-runtime.lib
        ${BDWGC_LIBS}
)

target_include_directories(typlyp PRIVATE
        ${LLVM_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/include
        ${CMAKE_CURRENT_SOURCE_DIR}/grammar
)