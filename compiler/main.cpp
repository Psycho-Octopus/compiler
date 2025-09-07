#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>
#include "Token.hpp"
#include "parser/parser.hpp"
#include "lexer/lexer.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Incorrect usage, correct usage:" << std::endl;
    std::cerr << "solusc <file> <arguments>" << std::endl;
    return 1;
  }
  std::string contents;
  {
    std::stringstream ContentsStream;
    std::fstream input(argv[1], std::ios::in);
    ContentsStream << input.rdbuf();
    contents = ContentsStream.str();
  }

  lexer lexer;
  parser parser;


  std::vector<Token> tokens = lexer.tokenize(contents);

  return 0;
}
