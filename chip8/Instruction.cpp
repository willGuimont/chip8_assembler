//
// Created by william on 2020-06-13.
//

#include "Instruction.h"


Instruction::Instruction(InstructionType instructionType, unsigned int x, unsigned int y, unsigned int n,
                         unsigned int kk,
                         unsigned int nnn) : instructionType(instructionType), n(n), x(x), y(y),
                                             kk(kk), nnn(nnn) {}

Instruction Instruction::fromAddress(InstructionType instructionType, unsigned int nnn) {
    return Instruction(instructionType, 0, 0, 0, 0, nnn);
}

Instruction Instruction::fromRegister(InstructionType instructionType, unsigned int x) {
    return Instruction(instructionType, x, 0, 0, 0, 0);
}

Instruction Instruction::fromRegisterByte(InstructionType instructionType, unsigned int x, unsigned int kk) {
    return Instruction(instructionType, x, 0, 0, kk, 0);
}

Instruction Instruction::fromTwoRegisters(InstructionType instructionType, unsigned int x, unsigned int y) {
    return Instruction(instructionType, x, y, 0, 0, 0);
}

Instruction Instruction::fromTwoRegistersAndNibble(InstructionType instructionType, unsigned int x, unsigned int y,
                                                   unsigned int n) {
    return Instruction(instructionType, x, y, n, 0, 0);
}

unsigned int Instruction::getByteCode() const {
    unsigned int baseCode = 0;
    switch (instructionType) {
        case InstructionType::System:
            baseCode = 0;
            break;
        case InstructionType::Clear:
            baseCode = 0x00E0u;
            break;
        case InstructionType::Return:
            baseCode = 0x00EEu;
            break;
        case InstructionType::Jump:
            baseCode = 0x1000u;
            break;
        case InstructionType::Call:
            baseCode = 0x2000u;
            break;
        case InstructionType::SkipEqualByte:
            baseCode = 0x3000u;
            break;
        case InstructionType::SkipNotEqualByte:
            baseCode = 0x4000u;
            break;
        case InstructionType::SkipEqualRegister:
            baseCode = 0x5000u;
            break;
        case InstructionType::LoadByte:
            baseCode = 0x6000u;
            break;
        case InstructionType::AddByte:
            baseCode = 0x7000u;
            break;
        case InstructionType::LoadRegister:
            baseCode = 0x8000u;
            break;
        case InstructionType::Or:
            baseCode = 0x8001u;
            break;
        case InstructionType::And:
            baseCode = 0x8002u;
            break;
        case InstructionType::Xor:
            baseCode = 0x8003u;
            break;
        case InstructionType::AddRegister:
            baseCode = 0x8004u;
            break;
        case InstructionType::Sub:
            baseCode = 0x8005u;
            break;
        case InstructionType::ShiftRight:
            baseCode = 0x8006u;
            break;
        case InstructionType::SubFrom:
            baseCode = 0x8007u;
            break;
        case InstructionType::ShiftLeft:
            baseCode = 0x800Eu;
            break;
        case InstructionType::SkipNotEqualRegister:
            baseCode = 0x9000u;
            break;
        case InstructionType::LoadIndex:
            baseCode = 0xA000u;
            break;
        case InstructionType::JumpTo:
            baseCode = 0xB000u;
            break;
        case InstructionType::Random:
            baseCode = 0xC000u;
            break;
        case InstructionType::Draw:
            baseCode = 0xD000u;
            break;
        case InstructionType::SkipPressed:
            baseCode = 0xE09Eu;
            break;
        case InstructionType::SkipNotPressed:
            baseCode = 0xE0A1u;
            break;
        case InstructionType::LoadDelayTimer:
            baseCode = 0xF007u;
            break;
        case InstructionType::LoadKey:
            baseCode = 0xF00Au;
            break;
        case InstructionType::SetDelayTimer:
            baseCode = 0xF015u;
            break;
        case InstructionType::SetSoundTimer:
            baseCode = 0xF018u;
            break;
        case InstructionType::AddIndex:
            baseCode = 0xF01Eu;
            break;
        case InstructionType::LoadFontLocation:
            baseCode = 0xF029u;
            break;
        case InstructionType::LoadBinaryCodedDigit:
            baseCode = 0xF033u;
            break;
        case InstructionType::WriteRegisters:
            baseCode = 0xF055u;
            break;
        case InstructionType::ReadRegisters:
            baseCode = 0xF065u;
            break;
    }

    return baseCode | n | (x << 2u) | (y << 1u) | kk | nnn;;
}
