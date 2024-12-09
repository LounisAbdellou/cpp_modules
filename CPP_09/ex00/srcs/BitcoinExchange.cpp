#include "BitcoinExchange.hpp"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <limits>

static bool checkRate(const std::string &str) {
  if (str.empty())
    return false;

  char *ptr;
  size_t i = 0;
  strtof(str.c_str(), &ptr);
  while (std::isdigit(str[i]))
    i++;
  return (*ptr) == '\0' || i == str.size();
}

static bool checkDate(const std::string &str) {
  (void)str;
  return true;
}

BitcoinExchange::BitcoinExchange(const std::string &filename) {
  this->csvHandler();
  this->executeInput(filename);
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
    line.erase(0, pos);
    value = atof(line.c_str());

    if (std::isinf(value) || !checkDate(key) || !checkRate(line.c_str())) {
      csv.close();
      return; // MUST THROW EXCEPTION THERE
    }

    this->bitcoinValues[key] = value;
  }

  csv.close();
}

void BitcoinExchange::executeInput(const std::string &filename) {
  std::ifstream inputFile;

  inputFile.open(filename.c_str());
  if (!inputFile.is_open())
    return; // MUST THROW EXCEPTION THERE

  inputFile.close();
}
