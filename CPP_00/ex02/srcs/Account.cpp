#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp() {
  std::time_t now = std::time(0);
  std::tm *ltm = std::localtime(&now);

  std::cout << "[" << ltm->tm_year + 1900;
  std::cout << (ltm->tm_mon < 10 ? "0" : "") << ltm->tm_mon;
  std::cout << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday;
  std::cout << "_" << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "] ";
}

Account::Account(int initial_deposit) {
  this->_amount = 0;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;

  this->_accountIndex = this->_nbAccounts;
  this->_amount += initial_deposit;
  this->_totalAmount += initial_deposit;
  _nbAccounts += 1;

  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "created\n";
}

Account::~Account() {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "closed\n";
}

int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";";
  std::cout << "total:" << getTotalAmount() << ";";
  std::cout << "deposits:" << getNbDeposits() << ";";
  std::cout << "withdrawals:" << getNbWithdrawals() << "\n";
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount << ";";
  std::cout << "deposit:" << deposit << ";";

  this->_amount += deposit;
  this->_nbDeposits += 1;
  _totalAmount += deposit;
  _totalNbDeposits += 1;

  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_deposits:" << this->_nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount << ";";

  if (withdrawal > this->_amount) {
    std::cout << "withdrawal:refused\n";
    return false;
  }

  std::cout << "withdrawal:" << withdrawal << ";";

  this->_amount -= withdrawal;
  this->_nbWithdrawals += 1;
  _totalAmount -= withdrawal;
  _totalNbWithdrawals += 1;

  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_withdrawals:" << this->_nbWithdrawals << "\n";

  return true;
}

int Account::checkAmount() const { return this->_amount; }

void Account::displayStatus() const {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "deposits:" << this->_nbDeposits << ";";
  std::cout << "withdrawals:" << this->_nbWithdrawals << "\n";
}
