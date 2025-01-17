#pragma once
#include <iostream>
#include <string>

class CodegenException final : public std::runtime_error {
public:
    explicit CodegenException(const std::string& _Message)
        : runtime_error(_Message) {
    }

    explicit CodegenException(const char* _Message)
        : runtime_error(_Message) {
    }
};

class UnknownExecutionTypeException final : public std::runtime_error {
public:
    explicit UnknownExecutionTypeException(const std::string& _Message)
            : runtime_error(_Message) {
    }

    explicit UnknownExecutionTypeException(const char* _Message)
            : runtime_error(_Message) {
    }
};

class Logger {
public:
    static void log(const std::string& messages...) {
        for (const auto& message : messages) {
            std::cout << message;
        }
        std::cout << std::endl;
    }

    static void debug(const std::string& messages...) {
        std::cout << "[DEBUG] ";
        for (const auto& message : messages) {
            std::cout << message;
        }
        std::cout << std::endl;
    }

    static void info(const std::string& messages...) {
        std::cout << "[INFO] ";
        for (const auto& message : messages) {
            std::cout << message;
        }
        std::cout << std::endl;
    }

    static void error(const std::string& messages...) {
        std::cerr << "[ERROR] ";
        for (const auto& message : messages) {
            std::cerr << message;
        }
        std::cerr << std::endl;
    }
};

inline std::string read_file_name(int argc, char* argv[]) {
    if (argc < 2) {
        Logger::error("Usage: typlyp <input_file> <compilation_type -I|-C");
        exit(1);
    }

    std::string input_file = argv[1];

    return input_file;
}

inline std::string read_file(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        Logger::error("File ", &fileName, " could not be opened");
        return std::string();
    }

    std::string contents(std::istreambuf_iterator{file}, {});
    file.close();

    return contents;
}

inline std::string interpret_or_compile(int argc, char* argv[]) {
    if (argc < 2) {
        Logger::error("Usage: typlyp <input_file> <compilation_type -I|-C");
        exit(1);
    }

    std::string flag = argv[2];

    return flag;
}