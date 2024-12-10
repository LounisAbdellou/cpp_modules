#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

class PmergeMe {
private:
public:
  PmergeMe();
  PmergeMe(const PmergeMe &src);
  ~PmergeMe();

  PmergeMe &operator=(const PmergeMe &src);
};

#endif // !PMERGE_ME_HPP
