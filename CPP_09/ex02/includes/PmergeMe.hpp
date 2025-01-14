#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

// #include <chrono>
#include <deque>
#include <string>
#include <vector>

class PmergeMe {
  // typedef typename std::chrono::time_point<std::chrono::system_clock>
  // TimePoint;

public:
  PmergeMe() {}
  PmergeMe(int ac, char **av);
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &src);
  ~PmergeMe() {}

  void sortVector();
  void sortDeque();

private:
  std::deque<int> _deque;
  std::vector<int> _vector;

  long long _getCurrentTimeInMs() const;

  long _jacobsthalNumber(long n);
  template <typename t> void _swapPair(t it, int pair_level);
  template <typename t> void _sortContainer(t &container, int level);
  template <typename t>
  void _printState(const std::string &prefix, t &container) const;
};

template <typename T> T next(T it, int steps) {
  std::advance(it, steps);
  return it;
}
template <typename T> bool compare(T lv, T rv) { return *lv < *rv; }

#endif // !PMERGE_ME_HPP
