#include "Span.hpp"
#include <algorithm>

Span::Span() {
  this->_size = 0;
  this->_count = 0;
}

Span::Span(unsigned int n) {
  this->_size = n;
  this->_count = 0;
}

Span::Span(const Span &src) { *this = src; }

Span &Span::operator=(const Span &src) {
  if (this == &src)
    return *this;

  this->_size = src._size;
  this->_count = src._count;
  std::copy(src._array.begin(), src._array.end(), this->_array.begin());

  return *this;
}

void Span::addNumber(int n) {
  if (this->_count >= this->_size)
    return;

  this->_array.push_back(n);
  this->_count++;
}

void Span::addMultipleNumbers(std::vector<int> numbers) {
  if (numbers.size() > (this->_size - this->_count))
    return;

  this->_array.insert(this->_array.end(), numbers.begin(), numbers.end());
}

size_t Span::shortestSpan() {
  size_t span;
  std::sort(this->_array.begin(), this->_array.end());
  std::vector<int>::const_iterator curr;
  std::vector<int>::const_iterator next;

  curr = this->_array.begin();
  next = this->_array.begin() + 1;
  span = (*next - *curr);

  while (next != this->_array.end()) {
    if ((size_t)(*next - *curr) < span)
      span = (*next - *curr);

    curr++;
    next++;
  }

  return span;
}

size_t Span::longestSpan() {
  std::sort(this->_array.begin(), this->_array.end());
  std::vector<int>::const_iterator first;
  std::vector<int>::const_iterator last;

  first = this->_array.begin();
  last = first + this->_array.size() - 1;

  return *last - *first;
}
