#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

#include "Token.hpp"
#include "generator/gen.hpp"
#include "lexer/lexer.hpp"
#include "parser/parser.hpp"

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
  generator gen;

  std::vector<Token> tokens = lexer.tokenize(contents);
  std::string output = gen.codeGen(tokens);

  system("touch out.ssa");
  std::fstream out("out.ssa");
  out << output;

  /*system("qbe out.ssa > out.s");
  system("gcc out.s -o out");*/

  return 0;
}
