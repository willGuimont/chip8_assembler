#include <iostream>
#include <string>
#include <fstream>

#include "lexer/Lexer.h"
#include "parser/Parser.h"

int main(int argc, char **argv) {

    if (argc != 3) {
        std::cout << "Usage:" << std::endl
                  << "chip8_assembler source.c8 output" << std::endl;
        return 0;
    }

    std::ifstream file(argv[1]);
    std::string source;

    file.seekg(0, std::ios::end);
    source.reserve(file.tellg());
    file.seekg(0, std::ios::beg);

    source.assign(std::istreambuf_iterator<char>(file),
                  std::istreambuf_iterator<char>());
    file.close();

    Lexer lexer;
    const std::vector<Token> tokens = lexer.scan(source);

    bool hadTokenError = false;
    for (const auto t : tokens) {
        if (t.getTokenType() == Token::TokenType::Error) {
            std::cout << "Error occured when scanning source code" << std::endl;
            std::cout << t.getLiteral() << std::endl;
            std::cout << "On line " << t.getLineNumber() << std::endl;
            hadTokenError = true;
        }
    }

    if (hadTokenError) {
        std::cout << "Tokenization error" << std::endl;
        std::exit(1);
    }

    auto parser = Parser();
    const auto instructions = parser.parse(tokens);

    bool hadParsingError = false;
    for (const auto i : instructions) {
        if (i.getInstructionType() == Instruction::InstructionType::SyntaxError) {
            std::cout << "A syntax error occured when parsing source code" << std::endl;
            std::cout << i.getErrorMessage().value() << std::endl;
            std::cout << "On line " << i.getErrorLineNumber() << std::endl;
            hadParsingError = true;
        }
    }

    if (hadParsingError) {
        std::cout << "Parsing error" << std::endl;
        std::exit(1);
    }

    std::ofstream output(argv[2], std::ios::binary);
    for (const auto i : instructions) {
        unsigned int bytecode = i.getByteCode();
        unsigned char higher = bytecode >> (8);
        unsigned char lower = bytecode & 0xFF;
        output << higher << lower;
    }
    output.close();

    return 0;
}
