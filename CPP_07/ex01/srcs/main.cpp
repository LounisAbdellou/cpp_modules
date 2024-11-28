#include "iter.hpp"
#include <iostream>
#include <string>

static void init(std::string &str) { str = "init"; }

int main() {
  size_t len = 5;
  std::string array[len];

  iter(array, len, &init);

  for (size_t i = 0; i < len; i++) {
    std::cout << array[i] << std::endl;
  }

  return 0;
}
