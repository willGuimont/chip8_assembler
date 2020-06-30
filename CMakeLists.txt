cmake_minimum_required(VERSION 3.16)
project(chip8_assembler)

set(CMAKE_CXX_STANDARD 20)

add_executable(chip8_assembler main.cpp lexer/Lexer.cpp lexer/Lexer.h chip8/Instruction.cpp chip8/Instruction.h lexer/Token.h lexer/Token.cpp parser/Parser.cpp parser/Parser.h)
