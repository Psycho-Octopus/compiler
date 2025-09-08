#!/bin/sh

clang++ -I ~/projects/solusc/include compiler/main.cpp compiler/generator/gen.cpp compiler/lexer/lexer.cpp `llvm-config --cxxflags --ldflags --libs core` -o solusc -g
