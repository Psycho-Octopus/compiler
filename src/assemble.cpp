#include "assemble.hpp"
#include "Token.hpp"
#include <sstream>

std::string codeGen(const std::vector<Token>& tokens) {
  std::stringstream output;
  output <<  "global _start\nstart:\n";

  for (int i = 0; i < tokens.size(); i++) {
    const Token& token = tokens.at(i);
    if (token.type == TokenType::RETURN) {
      if (i + 1 < tokens.size() && tokens.at(i + 1).type == TokenType::INT) {
        if (i + 2 < tokens.size() && tokens.at(i + 2).type == TokenType::SEMICOLON) {
          output << "    mov rax, 60\n";
          output << "    mov rdi, " << tokens.at(i + 1).value.value() << "\n";
          output << "    syscall";
        }

      }
    }
    
  }
  return output.str();
}
