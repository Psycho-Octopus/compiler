#pragma once

#include "../Token.hpp"
#include <string>
#include <vector>

class generator {
public:
  std::string codeGen(const std::vector<Token> tokens);
  std::string optimise(const std::string code);
};
