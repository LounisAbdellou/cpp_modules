#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
  if (this == &src)
    return *this;

  this->bitcoinValues = src.bitcoinValues;

  return *this;
}

bool BitcoinExchange::fileParser(const std::ifstream &file) {
  std::string line;

  (void)file;
  // while (std::getline(file, line)) {
  // }

  return true;
}
