#include "gen.hpp"
#include <sstream>
#include <string>
#include <vector>

std::string generator::codeGen(const std::vector<Token> tokens) {
  // We stream QBE code into this
  std::stringstream contents;

  // starting point
  contents << "export function w $main() {" << "\n" << "@start" << "\n    ";

  for (size_t i = 0; i < tokens.size(); i++) {
    if (tokens[i].type == TokenType::RETURN) {
      contents << "ret ";
      if (tokens[i + 1].type == TokenType::IDENTIFIER) {
        contents << "%";
      }
    }
    if (tokens[i].type == TokenType::INT && tokens[i].value.has_value()) {
      contents << tokens[i].value.value();
    }
    if (tokens[i].type == TokenType::SEMICOLON) {
      contents << "\n    ";
    }
    if (tokens[i].type == TokenType::VAR) {
      contents << "%";
    }
    if (tokens[i].type == TokenType::IDENTIFIER) {
      contents << tokens[i].value.value();
    }
    if (tokens[i].type == TokenType::EQUAL) {
      contents << " =w copy ";
    }
  }

  contents << "}\n";

  return contents.str();
}

std::string generator::optimise(const std::string str) {}
