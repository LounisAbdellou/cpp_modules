#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <cstdlib>
#include <stack>

template <class T> class MutantStack : public std::stack<T> {
public:
  typedef typename std::deque<T>::iterator iterator;
  typedef typename std::deque<T>::const_iterator const_iterator;
  typedef typename std::deque<T>::reverse_iterator reverse_iterator;
  typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

  MutantStack() {};
  MutantStack(const MutantStack &src) { *this = src; };
  ~MutantStack() {};

  MutantStack &operator=(const MutantStack &src) {
    if (this == &src)
      return *this;

    this->c = src.c;

    return *this;
  };

  iterator begin() { return this->c.begin(); };
  iterator end() { return this->c.end(); };

  const_iterator cbegin() const { return this->c.cbegin(); };
  const_iterator cend() const { return this->c.cend(); };

  reverse_iterator rbegin() { return this->c.rbegin(); };
  reverse_iterator rend() { return this->c.rend(); };

  const_reverse_iterator crbegin() const { return this->c.crbegin(); };
  const_reverse_iterator crend() const { return this->c.crend(); };
};

#endif // !MUTANT_STACK_HPP
