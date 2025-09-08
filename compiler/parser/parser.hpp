#pragma once

#include <iostream>
#include <optional>
#include <ostream>
#include <vector>

#include "../Token.hpp"
#include "../helper.hpp"

namespace node {

struct Expr {
  Token INT;
};

struct Exit {
  node::Expr expr;
};
}; // namespace node

std::optional<node::Exit> parse(const std::vector<Token> &tokens);

std::optional<Token> parseExpr(const std::vector<Token> &tokens);
