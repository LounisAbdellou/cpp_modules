#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <deque>
#include <string>
#include <vector>

class PmergeMe {
private:
  double _dequeTime;
  double _vectorTime;
  std::deque<int> _deque;
  std::vector<int> _vector;

public:
  PmergeMe();
  PmergeMe(const PmergeMe &src);
  PmergeMe(int ac, char **av);
  ~PmergeMe();

  PmergeMe &operator=(const PmergeMe &src);

  void sortVector();
  std::vector<int> &mergeVector(std::vector<int> &vec);

  void printState(const std::string &prefix) const;
};

#endif // !PMERGE_ME_HPP
