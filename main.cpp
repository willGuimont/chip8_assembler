#include <iostream>
#include <string>
#include <fstream>

#include "lexer/Lexer.h"

int main(int argc, char** argv) {

    if (argc != 2) {
        std::cout << "Usage:" << std::endl
                  << "chip8_assembler source.c8" << std::endl;
        return 0;
    }

    // TODO error handling
    std::ifstream file(argv[1]);
    std::string source;

    file.seekg(0, std::ios::end);
    source.reserve(file.tellg());
    file.seekg(0, std::ios::beg);

    source.assign(std::istreambuf_iterator<char>(file),
                  std::istreambuf_iterator<char>());

    Lexer lexer;
    const auto tokens = lexer.parse(source);

    for (const auto t : tokens) {
        std::cout << t.toString() << std::endl;
    }

    return 0;
}
