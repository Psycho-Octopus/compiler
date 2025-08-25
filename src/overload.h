#ifndef OVERLOAD_H
#define OVERLOAD_H

#include <iostream>
#include <string>
#include <optional>
#include "Token.hpp"

// Operator for TokenType enum
std::ostream& operator<<(std::ostream& os, const TokenType& type);

// Operator for Token struct  
std::ostream& operator<<(std::ostream& os, const Token& token);

#endif
