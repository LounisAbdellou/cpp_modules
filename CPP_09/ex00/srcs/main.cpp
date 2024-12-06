#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Error: wrong arguments." << std::endl;
    return 1;
  }

  try {
    BitcoinExchange btc;

    btc.executeInput(av[1]);
  } catch (const std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}
