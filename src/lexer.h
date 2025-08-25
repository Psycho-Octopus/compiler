#ifndef LEXER_H
#define LEXER_H

#include "Token.hpp"
#include <vector>

std::vector<Token> tokenize(const std::string &str);

#endif
