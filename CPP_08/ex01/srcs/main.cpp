#include "Span.hpp"
#include <iostream>

int main(void) {
  Span span(10);
  int numbers[] = {20, 1, 2, 17, 3, 4, 5, 6, 18, 19};
  size_t len = sizeof(numbers) / sizeof(numbers[0]);
  std::vector<int> copy(numbers, numbers + len);

  span.addMultipleNumbers(copy);
  std::cout << span.shortestSpan() << std::endl;
  std::cout << span.longestSpan() << std::endl;

  return 0;
}
