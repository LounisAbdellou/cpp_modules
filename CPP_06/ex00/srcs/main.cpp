#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Error: wrong argument" << std::endl;
    return 1;
  }

  ScalarConverter::convert(av[1]);

  return 0;
}
