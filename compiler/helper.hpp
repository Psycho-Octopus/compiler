#pragma once

#include <iostream>
#include <optional>
#include <string>

inline void Warning(const std::string &message) {
  std::cerr << "Warning: " << message << std::endl;
}

inline void Error(const std::string &err) {
  std::cerr << "ERROR: " << err << std::endl;
  exit(1);
}

inline std::optional<char> peek(int index, std::string src, int ahead = 1) {
  if (index + ahead >= src.length()) {
    return {};
  } else {
    return src.at(index);
  }
}
