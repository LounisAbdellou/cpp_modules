#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <map>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, int> bitcoinValues;

public:
  BitcoinExchange() {};
  BitcoinExchange(const BitcoinExchange &src);
  ~BitcoinExchange() {};

  BitcoinExchange &operator=(const BitcoinExchange &src);

  bool fileParser(const std::ifstream &file);
};

#endif // !BITCOIN_EXCHANGE_HPP
