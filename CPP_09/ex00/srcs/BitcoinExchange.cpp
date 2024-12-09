#include "BitcoinExchange.hpp"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <limits>

static bool isFloatOrInt(const std::string &str) {
  if (str.empty())
    return false;

  char *ptr;
  size_t i = 0;
  strtof(str.c_str(), &ptr);
  while (std::isdigit(str[i]))
    i++;
  return (*ptr) == '\0' || i == str.size();
}

BitcoinExchange::BitcoinExchange(const std::string &inputFilename) {
  this->csvHandler();
  (void)inputFilename;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
  if (this == &src)
    return *this;

  this->bitcoinValues = src.bitcoinValues;

  return *this;
}

#include <iostream>
void BitcoinExchange::csvHandler() {
  size_t pos;
  float value;
  std::string key;
  std::string line;
  std::ifstream csv;

  csv.open("data.csv");
  if (!csv.is_open())
    return; // MUST THROW EXCEPTION THERE

  csv.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  while (std::getline(csv, line)) {
    pos = line.find(',');
    key = line.substr(0, pos++);
    value = atof(line.c_str() + pos);

    std::cout << key << " | " << line.c_str() + pos << std::endl;

    if (std::isinf(value) || !isFloatOrInt(line.c_str() + pos))
      return; // MUST THROW EXCEPTION THERE

    this->bitcoinValues[key] = value;
  }
}
