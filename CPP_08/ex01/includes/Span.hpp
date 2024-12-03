#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstdlib>
#include <vector>

class Span {
private:
  std::vector<int> _array;
  unsigned int _size;
  unsigned int _count;

public:
  Span();
  Span(unsigned int n);
  Span(const Span &src);
  ~Span() {};

  Span &operator=(const Span &src);

  void addNumber(int n);
  void addMultipleNumbers(std::vector<int> numbers);

  size_t shortestSpan();
  size_t longestSpan();
};

#endif // !SPAN_HPP
