#pragma once
#include <iostream>
#include <string>

class Logger {
public:
    void log(const std::string& messages...) const {
        for (const auto& message : messages) {
            std::cout << message;
        }
        std::cout << std::endl;
    }

    void debug(const std::string& messages...) const {
        std::cout << "[DEBUG] ";
        for (const auto& message : messages) {
            std::cout << message;
        }
        std::cout << std::endl;
    }

    void info(const std::string& messages...) const {
        std::cout << "[INFO] ";
        for (const auto& message : messages) {
            std::cout << message;
        }
        std::cout << std::endl;
    }

    void error(const std::string& messages...) const {
        std::cerr << "[ERROR] ";
        for (const auto& message : messages) {
            std::cerr << message;
        }
        std::cerr << std::endl;
    }
};

std::string readFile(const std::string& fileName) {
    const std::string path = "../scratches/" + fileName; //тут у меня путь другой, специально не меняю в общей ветке

    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "File " << path << " does not exist" << std::endl;
        return std::string();
    }

    std::string contents(std::istreambuf_iterator<char>{file}, {});
    file.close();

    return contents;
}
