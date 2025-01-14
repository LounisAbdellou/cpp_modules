#include "RPN.hpp"
#include <cstdlib>
#include <iostream>

bool isOperator(char c) {
  if (c == '+' || c == '-' || c == '*' || c == '/')
    return true;

  return false;
}

RPN::RPN(const std::string &operation) {
  int tmp;
  std::string::const_iterator it;

  for (it = operation.begin(); it != operation.end(); it++) {
    if (std::isdigit(*it)) {
      if (*(it + 1) != ' ' && it + 1 != operation.end())
        throw std::invalid_argument("invalid argument found");

      this->_numbers.push(*it - 48);
    } else if (isOperator(*it)) {
      if (this->_numbers.size() < 2)
        throw std::invalid_argument("invalid operation");
      else if (*(it + 1) != ' ' && it + 1 != operation.end())
        throw std::invalid_argument("invalid argument found");

      tmp = this->_numbers.top();
      this->_numbers.pop();

      if (*it == '+')
        this->_numbers.top() += tmp;
      else if (*it == '-')
        this->_numbers.top() -= tmp;
      else if (*it == '*')
        this->_numbers.top() *= tmp;
      else if (*it == '/') {
        if (tmp < 1)
          throw std::invalid_argument("invalid operation");
        this->_numbers.top() /= tmp;
      }
    } else if (*it != ' ') {
      throw std::invalid_argument("invalid argument found");
    }
  }

  if (this->_numbers.size() > 1)
    throw std::invalid_argument("invalid operation");
}

RPN::RPN(const RPN &src) { *this = src; }

RPN &RPN::operator=(const RPN &src) {
  if (this == &src)
    return *this;

  this->_numbers = src._numbers;

  return *this;
}

void RPN::printResult() const {
  std::cout << this->_numbers.top() << std::endl;
}
