#!/bin/sh

clang++ -I ~/projects/solusc/include compiler/main.cpp compiler/lexer/lexer.cpp compiler/parser/parser.cpp `llvm-config --cxxflags --ldflags --libs core` -o solusc -g
