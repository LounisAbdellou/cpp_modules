#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av) {
  std::ifstream file;
  std::string filename;
  bool isExtentionValid;
  BitcoinExchange bitcoinExchange;

  if (ac != 2) {
    std::cout << "Error: wrong arguments." << std::endl;
    return 1;
  }

  file.open(av[1]);
  filename = av[1];
  if (!file.is_open()) {
    std::cout << "Error: could not open file." << std::endl;
    return 1;
  }

  isExtentionValid = filename.size() == filename.rfind(".csv") + 4;
  if (!isExtentionValid || !bitcoinExchange.fileParser(file)) {
    file.close();
    std::cout << "Error: file is not valid." << std::endl;
    return 1;
  }

  return 0;
}
