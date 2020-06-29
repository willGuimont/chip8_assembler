//
// Created by william on 2020-06-25.
//

#include <stdexcept>
#include "Token.h"

Token::Token(Token::TokenType tokenType, const std::string &lexeme, const std::string &literal, int lineNumber)
        : tokenType(tokenType), lexeme(lexeme), literal(literal), lineNumber(lineNumber) {}

Token::TokenType Token::getTokenType() const {
    return tokenType;
}

const std::string &Token::getLexeme() const {
    return lexeme;
};

const std::string &Token::getLiteral() const {
    return literal;
}

int Token::getLineNumber() const {
    return lineNumber;
}

std::string Token::toString() const {
    std::ostringstream out;
    switch (tokenType) {
        case Token::TokenType::Clear:
            return "CLS";
            break;
        case Token::TokenType::Return:
            return "RET";
            break;
        case Token::TokenType::Jump:
            return "JP";
            break;
        case Token::TokenType::Call:
            return "CALL";
            break;
        case Token::TokenType::SkipNextIfEqual:
            return "SE";
            break;
        case Token::TokenType::SkipNextIfNotEqual:
            return "SNE";
            break;
        case Token::TokenType::Load:
            return "LD";
            break;
        case Token::TokenType::Add:
            return "ADD";
            break;
        case Token::TokenType::Or:
            return "OR";
            break;
        case Token::TokenType::And:
            return "AND";
            break;
        case Token::TokenType::Xor:
            return "XOR";
            break;
        case Token::TokenType::Sub:
            return "SUB";
            break;
        case Token::TokenType::SubFrom:
            return "SUBN";
            break;
        case Token::TokenType::ShiftRight:
            return "SHR";
            break;
        case Token::TokenType::ShiftLeft:
            return "SHL";
            break;
        case Token::TokenType::Random:
            return "RND";
            break;
        case Token::TokenType::Draw:
            return "DRW";
            break;
        case Token::TokenType::SkipIfKeyPressed:
            return "SKP";
            break;
        case Token::TokenType::SkipIfNotKeyPressed:
            return "SKNP";
            break;
        case Token::TokenType::Index:
            return "I";
            break;
        case Token::TokenType::IndexAddress:

            out << "[" << literal << "]";
            return out.str();
            break;
        case Token::TokenType::DelayTimer:
            return "DT";
            break;
        case Token::TokenType::Key:
            return "K";
            break;
        case Token::TokenType::SoundTimer:
            return "ST";
            break;
        case Token::TokenType::Font:
            return "F";
            break;
        case Token::TokenType::BinaryCodedDigit:
            return "B";
            break;
        case Token::TokenType::Register:
            out << "R" << literal;
            return out.str();
            break;
        case Token::TokenType::Address:
        case Token::TokenType::Byte:
        case Token::TokenType::Nibble:
        case Token::TokenType::Word:
            out << "#" << literal;
            return out.str();
            break;
        case Token::TokenType::Section:
            return "SECTION";
            break;
        case Token::TokenType::DataSection:
            return ".data";
            break;
        case Token::TokenType::TextSection:
            return ".text";
            break;
        case Token::TokenType::Label:
            out << ":" << literal;
            return out.str();
            break;
        case Token::TokenType::Error:
            out << "Error on line (" << lineNumber;
            out << "): " << literal;
            return out.str();
            break;
        case Token::TokenType::EndOfFile:
            return "EOF";
            break;
        case Token::TokenType::EndOfLine:
            return "EOL";
            break;
        default:
            throw std::runtime_error("TokenType not handled");
    }
}

