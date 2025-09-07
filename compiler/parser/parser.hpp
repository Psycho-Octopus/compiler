#pragma once

#include "../Token.hpp"
#include <vector>
#include <optional>

namespace node {

    struct Expr {
       Token int_lit;
    };

    struct Exit {
       node::Expr expr;
    };
};

class parser {

    const std::vector<Token> tokens;
    size_t index = 0;

    public:
std::optional<node::Expr> parseExpr() {
node::Expr expr;

return expr;
}

std::optional<node::Exit> parse() {
    std::optional<node::Exit> exitNode;

    while (peek().has_value() && peek().value().type == TokenType::SEMICOLON) {}

    return exitNode;
}
private:
[[nodiscard]] inline std::optional<Token> peek(const int offset = 0) const
{
    if (index + offset >= tokens.size()) {
        return {};
    }
    return tokens.at(index + offset);
}

inline Token consume()
{
    return tokens.at(index++);
}

};
