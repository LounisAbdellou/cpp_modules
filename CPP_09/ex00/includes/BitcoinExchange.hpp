#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, float> bitcoinValues;

public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &src);
  ~BitcoinExchange() {};

  BitcoinExchange &operator=(const BitcoinExchange &src);

  void csvHandler();
  void executeInput(const std::string &filename);
};

#endif // !BITCOIN_EXCHANGE_HPP
