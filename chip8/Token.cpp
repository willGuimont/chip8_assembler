//
// Created by william on 2020-06-25.
//

#include "Token.h"

Token::Token(Token::TokenType tokenType, const std::string &lexeme, const std::string &literal, int lineNumber)
        : tokenType(tokenType), lexeme(lexeme), literal(literal), lineNumber(lineNumber) {}

Token::TokenType Token::getTokenType() const {
    return tokenType;
}

const std::string& Token::getLexeme() const {
    return lexeme;
};

const std::string &Token::getLiteral() const {
    return literal;
}

int Token::getLineNumber() const {
    return lineNumber;
}

