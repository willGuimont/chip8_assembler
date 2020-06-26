cmake_minimum_required(VERSION 3.16)
project(chip8_assembler)

set(CMAKE_CXX_STANDARD 20)

add_executable(chip8_assembler main.cpp lexer/Lexer.cpp lexer/Lexer.h chip8/Instruction.cpp chip8/Instruction.h chip8/Token.h chip8/Token.cpp)