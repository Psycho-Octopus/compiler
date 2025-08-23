#include <fstream>
#include <iostream>
#include <sstream>
#include "lexer.h"

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

  tokenize(contents);

  std::cout << contents << std::endl;

  return 0;
}

