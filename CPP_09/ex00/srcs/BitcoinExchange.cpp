#include "BitcoinExchange.hpp"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <limits>
#include <time.h>

static bool checkValue(const std::string &str) {
  if (str.empty())
    return false;

  char *ptr;
  size_t i = 0;
  strtof(str.c_str(), &ptr);
  while (std::isdigit(str[i]))
    i++;
  return (*ptr) == '\0' || i == str.size();
}

static bool checkDate(const std::string &date) {
  struct tm tm;

  if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
    return false;

  return true;
}

BitcoinExchange::BitcoinExchange() { this->csvHandler(); }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
  if (this == &src)
    return *this;

  this->bitcoinValues = src.bitcoinValues;

  return *this;
}

void BitcoinExchange::csvHandler() {
  size_t pos;
  float value;
  std::string key;
  std::string line;
  std::ifstream csv;

  csv.open("data.csv");
  if (!csv.is_open())
    throw std::invalid_argument("could not open data.csv");

  csv.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  while (std::getline(csv, line)) {
    pos = line.find(',');
    key = line.substr(0, pos++);
    line.erase(0, pos);
    value = atof(line.c_str());

    if (std::isinf(value) || !checkDate(key) || !checkValue(line.c_str())) {
      csv.close();
      throw std::invalid_argument("data.csv contain invalid values");
    }

    this->bitcoinValues[key] = value;
  }

  csv.close();
}

void BitcoinExchange::executeInput(const std::string &filename) {
  size_t pos;
  float mult;
  std::string date;
  std::string line;
  std::ifstream inputFile;
  std::map<std::string, float>::iterator it;

  inputFile.open(filename.c_str());
  if (!inputFile.is_open())
    throw std::invalid_argument("could not open input file");

  while (std::getline(inputFile, line)) {
    pos = line.find(" | ");
    if (pos == std::string::npos) {
      std::cout << "Error: invalid line format => " << line << '\n';
      continue;
    }

    date = line.substr(0, pos);
    pos += 3;
    line.erase(0, pos);
    mult = atof(line.c_str());

    if (!checkDate(date)) {
      std::cout << "Error: invalid date => " << date << '\n';
      continue;
    } else if (std::isinf(mult) || !checkValue(line.c_str())) {
      std::cout << "Error: invalid multiplier => " << mult << '\n';
      continue;
    }

    it = this->bitcoinValues.find(date);
    if (it == this->bitcoinValues.end()) {
      this->bitcoinValues[date] = -1;
      it = this->bitcoinValues.find(date);
      if (it == this->bitcoinValues.begin()) {
        std::cout << "Error: date not found => " << date << '\n';
        this->bitcoinValues.erase(it);
        continue;
      }
      this->bitcoinValues.erase(it--);
    }

    if (mult < 0)
      std::cout << "Error: multiplier is negative\n";
    else if ((*it).second * mult > 1000.00f || std::isinf((*it).second * mult))
      std::cout << "Error: result is too large\n";
    else if ((*it).second * mult < 0)
      std::cout << "Error: result is negative\n";
    else
      std::cout << date << " => " << line << " = " << (*it).second * mult
                << '\n';
  }

  inputFile.close();
}
