//
// Created by william on 2020-06-29.
//

#ifndef CHIP8_ASSEMBLER_PARSER_H
#define CHIP8_ASSEMBLER_PARSER_H

#include <vector>
#include <map>

#include "../lexer/Token.h"
#include "../chip8/Instruction.h"

class Parser {
public:
    std::vector<Instruction> parse(const std::vector<Token> &tokens);

private:
    Instruction error(std::string errorMessage, unsigned int lineNumber);
};


#endif //CHIP8_ASSEMBLER_PARSER_H
