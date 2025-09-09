#include <cctype>
#include <cstddef>
#include <string>
#include <vector>

#include "../Token.hpp"
#include "lexer.hpp"

std::vector<Token> lexer::tokenize(const std::string &str) {
  std::vector<Token> tokens;
  std::string buf;

  for (size_t i = 0; i < str.length(); i++) {
    char c = str[i];

    if (std::isalpha(c)) {
      buf.push_back(c);

      while (i + 1 < str.length() && std::isalnum(str[i + 1])) {
        i++;
        buf.push_back(str[i]);
      }

      if (buf == "return") {
        tokens.push_back({.type = TokenType::RETURN});
      } else if (buf == "var") {
        tokens.push_back({.type = TokenType::VAR});
      } else {
        tokens.push_back({.type = TokenType::IDENTIFIER, .value = buf});
      }

      buf.clear();
    }

    if (std::isdigit(c)) {
      buf.push_back(c);

      while (i + 1 < str.length() && std::isdigit(str[i + 1])) {
        i++;
        buf.push_back(str[i]);
      }

      tokens.push_back({.type = TokenType::INT, .value = buf});
      buf.clear();
    }

    switch (c) {
    case ';':
      tokens.push_back({.type = TokenType::SEMICOLON});
      break;
    case '=':
      tokens.push_back({.type = TokenType::EQUAL});
      break;
    case '//':
      tokens.push_back({.type = TokenType::SLASH_SLASH});
      break;
    }

    if (std::isspace(c)) {
      continue;
    }
  }

  return tokens;
}
