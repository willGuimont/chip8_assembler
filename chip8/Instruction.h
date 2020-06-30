//
// Created by william on 2020-06-13.
//

#ifndef CHIP8_ASSEMBLER_INSTRUCTION_H
#define CHIP8_ASSEMBLER_INSTRUCTION_H

#include <cstdint>

class Instruction {
private:
    enum class InstructionType {
        System,
        Clear,
        Return,
        Jump,
        Call,
        SkipEqualByte,
        SkipNotEqualByte,
        SkipEqualRegister,
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
        SkipNotEqualRegister,
        LoadIndex,
        JumpTo,
        Random,
        Draw,
        SkipPressed,
        SkipNotPressed,
        LoadDelayTimer,
        LoadKey,
        SetDelayTimer,
        SetSoundTimer,
        AddIndex,
        LoadFontLocation,
        LoadBinaryCodedDigit,
        WriteRegisters,
        ReadRegisters,
    };

    InstructionType instructionType;
    unsigned int n;
    unsigned int x;
    unsigned int y;
    unsigned int kk;
    unsigned int nnn;

    Instruction(InstructionType instructionType, unsigned int x, unsigned int y, unsigned int n, unsigned int kk,
                unsigned int nnn);

public:
    static Instruction fromAddress(InstructionType instructionType, unsigned int nnn);

    static Instruction fromRegister(InstructionType instructionType, unsigned int x);

    static Instruction fromRegisterByte(InstructionType instructionType, unsigned int x, unsigned int kk);

    static Instruction fromTwoRegisters(InstructionType instructionType, unsigned int x, unsigned y);

    static Instruction fromTwoRegistersAndNibble(InstructionType instructionType, unsigned int x, unsigned int y, unsigned int n);

    [[nodiscard]] unsigned int getByteCode() const;

};


#endif //CHIP8_ASSEMBLER_INSTRUCTION_H
