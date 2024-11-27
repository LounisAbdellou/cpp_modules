#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter {
private:
  ScalarConverter() {};
  ~ScalarConverter() {};

public:
  static void convert(const std::string &param);
};

#endif // !SCALAR_CONVERTER_HPP
