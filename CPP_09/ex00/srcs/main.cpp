#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Error: wrong arguments." << std::endl;
    return 1;
  }

  try {
    BitcoinExchange bitcoinExchange(av[1]);
  } catch (const std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  // file.open(av[1]);
  // filename = av[1];
  // if (!file.is_open()) {
  //   std::cout << "Error: could not open file." << std::endl;
  //   return 1;
  // }
  //
  // if (!bitcoinExchange.csvParser()) {
  //   std::cout << "Error: data.csv is not valid" << std::endl;
  //   return 1;
  // }
  //
  // isExtentionValid = filename.size() == filename.rfind(".txt") + 4;
  // if (!isExtentionValid ||) {
  //   file.close();
  //   std::cout << "Error: file is not valid." << std::endl;
  //   return 1;
  // }
  //
  return 0;
}
