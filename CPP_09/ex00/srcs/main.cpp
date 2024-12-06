#include <iostream>

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Error: wrong arguments" << std::endl;
    return 1;
  }

  std::cout << "test" << std::endl;
  return 0;
}
