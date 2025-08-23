#include <cctype>
#include <iostream>
#include <ostream>

#include "Token.hpp"
#include "lexer.h"

std::vector<Token> tokenize(const std::string &str) {
  std::vector<Token> tokens;
  std::string buf;

  for (int i = 0; i < str.length(); i++) {
    char c = str.at(i);
    if (std::isalpha(c)) {
      buf.push_back(c);
      i++;
      while (std::isalnum(str.at(i))) {
        buf.push_back(str.at(i));
        i++;
      }
      i--;

      if (buf == "return") {
        tokens.push_back({.type = TokenType::RETURN});
        buf.clear();
        continue;
      } else {
        std::cerr << "unreconized thingy" << std::endl;
        exit(1);
      }
    }
    else if (std::isdigit(c)) {
      buf.push_back(c);
      i++;
      while (std::isdigit(str.at(i))) {
        buf.push_back(str.at(i));
        i++;
      }
      i--;
      tokens.push_back( { .type = TokenType::INT, .value = buf } );
      buf.clear();
    }
    else if (c == ';') {
      tokens.push_back({.type = TokenType::SEMICOLON});
    } 
    else if (std::isspace(c)) {
      continue;
    } else {
        std::cerr << "unreconized thingy" << std::endl;
        exit(1);
    }
  }
  return tokens;
}
