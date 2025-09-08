#pragma once

#include <optional>
#include <string>

enum TokenType {
  // Single-character tokens.

  // ')'
  LEFT_PAREN,

  // '('
  RIGHT_PAREN,

  // '{'
  LEFT_BRACE,

  // '}'
  RIGHT_BRACE,

  // ','
  COMMA,

  // '.'
  DOT,

  // '-'
  MINUS,

  // '+'
  PLUS,

  // ':'
  COLON,

  // ';'
  SEMICOLON,

  // '/'
  SLASH,

  // '*'
  STAR,
  // One or two character tokens.
  // '!'
  BANG,

  // '!='
  BANG_EQUAL,

  // '='
  EQUAL,

  // '=='
  EQUAL_EQUAL,

  // '::'
  COLON_COLON,

  // '>'
  GREATER,

  // '>='
  GREATER_EQUAL,

  // '<'
  LESS,

  // '<='
  LESS_EQUAL,

  // Literals.
  IDENTIFIER,

  STRING,

  INT,

  FLOAT,

  BOOL,

  OPTIONAL,

  // Keywords.
  AND,

  CLASS,

  ELSE,

  FALSE,

  FUN,

  FOR,

  IF,

  NONE,

  OR,

  PRINT,

  RETURN,

  SUPER,

  TRUE,

  VAR,

  LET,

  WHILE,

  EXIT,

  // End of file
  EOF_
};

struct Token {
  TokenType type;
  int line;
  std::optional<std::string> value;
};
