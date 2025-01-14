#include <PmergeMe.hpp>
#include <cstdlib>
#include <iostream>

PmergeMe::PmergeMe() : _dequeTime(0.00), _vectorTime(0.00) {}

PmergeMe::PmergeMe(int ac, char **av) : _dequeTime(0.00), _vectorTime(0.00) {
  for (size_t i = 0; i < (size_t)ac; i++) {
    int n = atoi(av[i]);
    std::vector<int>::const_iterator it;

    for (size_t j = 0; av[i][j] != '\0'; j++) {
      if (!std::isdigit(av[i][j])) {
        throw std::invalid_argument("invalid argument found.");
      }
    }

    for (it = this->_vector.begin(); it != this->_vector.end(); it++) {
      if (*it == n) {
        throw std::invalid_argument("duplicate found.");
      }
    }

    this->_deque.push_back(n);
    this->_vector.push_back(n);
  }
}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
  if (this == &src) {
    this->_deque = src._deque;
    this->_vector = src._vector;
  }

  return *this;
}

PmergeMe::~PmergeMe() {}

std::size_t preceding_pow2(std::size_t v) {
  v--;
  v |= v >> 1;
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;
  return (++v) >> 1;
}

void PmergeMe::sortVector() {
  this->mergeVector(this->_vector);
  // std::cout << preceding_pow2(this->_vector.size()) << std::endl;

  // std::vector<int> left(this->_vector.begin(),
  //                             this->_vector.begin() + this->_vector.size() /
  //                             2);
  //
  // std::vector<int> right(this->_vector.begin() + this->_vector.size() /
  // 2,
  //                              this->_vector.end());

  this->_dequeTime = 1.00;
  this->_vectorTime = 1.00;
  // std::sort(split_lo.begin(), split_lo.end());
  // std::sort(split_hi.begin(), split_hi.end());

  // split_lo.insert(split_lo.end(), split_hi.begin(), split_hi.end());

  // std::sort(split_lo.begin(), split_lo.end());
}

std::vector<int> &PmergeMe::mergeVector(std::vector<int> &vec) {
  int half = vec.size() / 2;

  if (vec.size() < 2) {
    return vec;
  }

  std::vector<int> left(vec.begin(), vec.begin() + half);
  std::vector<int> right(vec.begin() + half, vec.end());

  left = mergeVector(left);
  right = mergeVector(right);

  if (left.back() > right.back()) {
    left.insert(left.begin(), right.begin(), right.end());
  } else {
    left.insert(left.end(), right.begin(), right.end());
  }

  vec = left;

  return vec;
}

void PmergeMe::printState(const std::string &prefix) const {
  std::vector<int>::const_iterator it;

  std::cout << prefix;

  for (it = this->_vector.begin(); it != this->_vector.end(); it++) {
    std::cout << *it;

    if (it + 1 != this->_vector.end()) {
      std::cout << ' ';
    }
  }

  std::cout << std::endl;
}
