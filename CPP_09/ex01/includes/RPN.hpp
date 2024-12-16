#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
private:
  std::stack<int> _numbers;

  static bool _isNumber(const char *str);

public:
  RPN() {};
  RPN(const std::string &operation);
  RPN(const RPN &src);
  ~RPN() {};

  RPN &operator=(const RPN &src);

  void printResult() const;
};

#endif // !RPN_HPP
