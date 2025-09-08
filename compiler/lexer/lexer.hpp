#pragma once

#include <vector>
// #include <optional>
#include <string>
/*#include <cctype>
#include <cstddef> */
#include "../Token.hpp"

class lexer {
public:
  std::vector<Token> tokenize(const std::string &str);
};

// std::vector<Token> tokenize(const std::string &str)
