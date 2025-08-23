#pragma once

#include <optional>
#include <string>
#include <vector>

enum class TokenType {
  // Single-character tokens.
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR, QUESTION,

  // One or two character tokens.
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  // Literals.
  IDENTIFIER, STRING, INT, FLOAT,

  // Keywords.
  AND, ELSE, FALSE, FUN, FOR, IF, NONE, OR,
  PRINT, RETURN, SUPER, THIS, TRUE, LET, VAR, WHILE,

  EOF_
};

struct Token {
  TokenType type;
  int line;
  std::optional<std::string> value {};
};
