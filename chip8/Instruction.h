//
// Created by william on 2020-06-13.
//

#ifndef CHIP8_ASSEMBLER_INSTRUCTION_H
#define CHIP8_ASSEMBLER_INSTRUCTION_H

#include <cstdint>
#include <histedit.h>
#include <optional>

#include "../lexer/Token.h"

class Instruction {
private:
    enum class InstructionType {
        System,
        Clear,
        Return,
        Jump,
        Call,
        SkipIfEqualByte,
        SkipIfNotEqualByte,
        SkipIfEqualRegister,
        LoadByte,
        AddByte,
        LoadRegister,
        Or,
        And,
        Xor,
        AddRegister,
        Sub,
        ShiftRight,
        SubFrom,
        ShiftLeft,
        SkipIfNotEqualRegister,
        LoadIndex,
        JumpTo,
        Random,
        Draw,
        SkipIfKeyPressed,
        SkipIfNotKeyPressed,
        LoadDelayTimer,
        LoadKey,
        SetDelayTimer,
        SetSoundTimer,
        AddIndex,
        LoadFontLocation,
        LoadBinaryCodedDigit,
        WriteRegisters,
        ReadRegisters,
        SyntaxError,
    };

    InstructionType instructionType;
    std::optional<unsigned int> n;
    std::optional<unsigned int> x;
    std::optional<unsigned int> y;
    std::optional<unsigned int> kk;
    std::optional<unsigned int> nnn;
    std::optional<Token> token;

    Instruction(InstructionType instructionType, std::optional<unsigned int> x, std::optional<unsigned int> y, std::optional<unsigned int> n, std::optional<unsigned int> kk,
                std::optional<unsigned int> nnn, std::optional<Token> token);

public:
    static Instruction fromNoParams(InstructionType instructionType);

    static Instruction fromAddress(InstructionType instructionType, unsigned int nnn);

    static Instruction fromRegister(InstructionType instructionType, unsigned int x);

    static Instruction fromRegisterByte(InstructionType instructionType, unsigned int x, unsigned int kk);

    static Instruction fromTwoRegisters(InstructionType instructionType, unsigned int x, unsigned y);

    static Instruction fromTwoRegistersAndNibble(InstructionType instructionType, unsigned int x, unsigned int y, unsigned int n);

    [[nodiscard]] unsigned int getByteCode() const;

};


#endif //CHIP8_ASSEMBLER_INSTRUCTION_H
