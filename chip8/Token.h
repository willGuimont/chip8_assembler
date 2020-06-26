//
// Created by william on 2020-06-25.
//

#ifndef CHIP8_ASSEMBLER_TOKEN_H
#define CHIP8_ASSEMBLER_TOKEN_H

#include <string>

class Token {
    public enum class TokenType {
        Clear,
        Return,
        Jump,
        Call,
        SkipNextIfEqualByte,
        SkipNextIfEqualRegister,
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
        SkipNextIfNotEqualRegister,
        SetIndex,
        JumpOf,
        Random,
        DisplaySprite,
        SkipIfKeyPressed,
        SkipIfNotKeyPressed,
        LoadTimer,
        WaitKeyPress,
        SetTimer,
        SetSoundTimer,
        AddIndex,
        LoadSpriteLocationIndex,
        BinaryCodedDecimal,
        StoreRegisters,
        ReadRegisters,
        Address,
        Constant,
        Register,
        Nible,
        IndexAddress,
        Section,
        DataSection,
        TextSection,
        LabelDeclaration,
        Label,
        Invalid,
    };
public:
    Token(TokenType tokenType, const std::string& lexeme, const std::string& literal, int lineNumber);

    TokenType getTokenType() const;
    const std::string& getLexeme() const;
    const std::string& getLiteral() const;
    int getLineNumber() const;
private:
    const TokenType tokenType;
    const std::string& lexeme;
    const std::string& literal;
    const unsigned int lineNumber;
};

#endif //CHIP8_ASSEMBLER_TOKEN_H
