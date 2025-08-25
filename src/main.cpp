#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>
#include "lexer.h"
#include "overload.h"
#include "assemble.hpp"

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

  std::vector<Token> tokens = tokenize(contents);

  std::cout << codeGen(tokens) << std::endl;

  {
    std::fstream file("out.asm", std::ios::out);
    file << codeGen(tokens);
  }

  system("nasm -felf64 out.asm");
  system("ld -o out out.o");
  system("rm out.o out.asm");

  return 0;
}

