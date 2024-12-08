#include <fstream>
#include <iostream>

static bool fileValidation(const std::string &filename) { return true; }

int main(int ac, char **av) {
  std::ifstream file;

  if (ac != 2) {
    std::cout << "Error: wrong arguments." << std::endl;
    return 1;
  }

  if (!fileValidation(av[1])) {
    std::cout << "Error: file is not valid." << std::endl;
    return 1;
  }

  file.open(av[1]);
  if (!file.is_open()) {
    std::cout << "Error: could not open file." << std::endl;
    return 1;
  }

  return 0;
}
