#include <PmergeMe.hpp>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <sys/time.h>

PmergeMe::PmergeMe(int ac, char **av) {
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

long long PmergeMe::_getCurrentTimeInMs() const {
  struct timeval tv;
  gettimeofday(&tv, NULL);

  return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

template <typename t>
void PmergeMe::_printState(const std::string &prefix, t &container) const {
  typename t::const_iterator it;

  std::cout << prefix;

  for (it = container.begin(); it != container.end(); it++) {
    std::cout << *it;

    if (it + 1 != container.end()) {
      std::cout << ' ';
    }
  }

  std::cout << "\r\n" << std::endl;
}

void PmergeMe::sortVector() {
  std::cout << "Merge Insertion Sort - std::vector\r\n" << std::endl;
  this->_printState("Before: ", this->_vector);
  long long startTime = this->_getCurrentTimeInMs();
  this->_sortContainer(this->_vector, 1);
  long long endTime = this->_getCurrentTimeInMs();
  this->_printState("After:  ", this->_vector);

  std::cout << "Time to process a range of " << this->_vector.size()
            << " elements with std::vector: " << endTime - startTime
            << " miliseconds" << std::endl;
}

void PmergeMe::sortDeque() {
  std::cout << "Merge Insertion Sort - std::deque\r\n" << std::endl;
  this->_printState("Before: ", this->_deque);
  long long startTime = this->_getCurrentTimeInMs();
  this->_sortContainer(this->_deque, 1);
  long long endTime = this->_getCurrentTimeInMs();
  this->_printState("After:  ", this->_deque);

  std::cout << "Time to process a range of " << this->_deque.size()
            << " elements with std::deque => " << endTime - startTime
            << " miliseconds" << std::endl;
}

long PmergeMe::_jacobsthalNumber(long n) {
  return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

template <typename T> void PmergeMe::_swapPair(T it, int pair_level) {
  T start = it + (-pair_level + 1);
  T end = start + pair_level;
  while (start != end) {
    std::iter_swap(start, start + pair_level);
    start++;
  }
}

template <typename t> void PmergeMe::_sortContainer(t &container, int level) {
  typedef typename t::iterator Iterator;

  int pairUnitsNbr = container.size() / level;
  if (pairUnitsNbr < 2)
    return;

  /* If there is an odd pair, we ignore it during swapping.
     It will go to the pend as the last pair. */
  bool isOdd = pairUnitsNbr % 2 == 1;

  /* It's important to caluclate the end position until which we should iterate.
     We can have a set of values like:
     ((1 2) (3 4)) ((3 8) (2 6)) | 0
     where there are numbers (0 in this case) which can't even form a pair.
     Those values should be ignored. */
  Iterator start = container.begin();
  Iterator last = container.begin() + (level * pairUnitsNbr);
  Iterator end = last + -(isOdd * level);

  /* Swap pairs of numbers, pairs, pairs of pairs etc by the biggest pair
     number. After each swap we recurse. */
  int jump = 2 * level;
  for (Iterator it = start; it != end; it += jump) {
    Iterator thisPair = it + (level - 1);
    Iterator nextPair = it + (level * 2 - 1);
    if (compare(nextPair, thisPair)) {
      this->_swapPair(thisPair, level);
    }
  }

  this->_sortContainer(container, level * 2);

  /* Main contains an already sorted sequence.
     Pend stores a yet to be sorted numbers.
     List data structure for quick random insertion and deletion.
     They contain iterators instead of the numbers themselves because
     iterators + level contain all the information about the stored
     ranges of numbers. */
  std::vector<Iterator> main;
  std::vector<Iterator> pend;

  /* Initialize the main chain with the {b1, a1}. */
  main.insert(main.end(), container.begin() + (level - 1));
  main.insert(main.end(), container.begin() + (level * 2 - 1));

  /* Insert the rest of a's into the main chain.
     Insert the rest of b's into the pend. */
  for (int i = 4; i <= pairUnitsNbr; i += 2) {
    pend.insert(pend.end(), container.begin() + (level * (i - 1) - 1));
    main.insert(main.end(), container.begin() + (level * i - 1));
  }

  /* Insert an odd element to the pend, if there are any. */
  if (isOdd) {
    pend.insert(pend.end(), end + (level - 1));
  }

  /* Insert the pend into the main in the order determined by the
     Jacobsthal numbers. For example: 3 2 -> 5 4 -> 11 10 9 8 7 6 -> etc.
     During insertion, main numbers serve as an upper bound for inserting
     numbers, in order to save number of comparisons, as we know already that,
     for example, b5 is lesser than a5, we binary search only until a5, not
     until the end of the container. We can calculate the index of the bound
     element. With the way I do it, the index of the bound is insertedNumbers +
     current_jacobsthal_number. */
  int prevJacobsthal = this->_jacobsthalNumber(1);
  int insertedNumbers = 0;
  for (int k = 2;; k++) {
    int currJacobsthal = this->_jacobsthalNumber(k);
    int jacobsthalDiff = currJacobsthal - prevJacobsthal;
    int offset = 0;
    if (jacobsthalDiff > static_cast<int>(pend.size()))
      break;
    int nbrOfTimes = jacobsthalDiff;
    typename std::vector<Iterator>::iterator pendIt =
        pend.begin() + (jacobsthalDiff - 1);
    typename std::vector<Iterator>::iterator boundIt =
        main.begin() + (currJacobsthal + insertedNumbers);
    while (nbrOfTimes) {
      typename std::vector<Iterator>::iterator idx =
          std::upper_bound(main.begin(), boundIt, *pendIt, compare<Iterator>);
      typename std::vector<Iterator>::iterator inserted =
          main.insert(idx, *pendIt);
      nbrOfTimes--;
      pendIt = pend.erase(pendIt);
      std::advance(pendIt, -1);
      /* Sometimes the inserted number in inserted at the exact index of where
         the bound should be. When this happens, it eclipses the bound of the
         next pend, and it does more comparisons than it should. We need to
         offset when this happens. */
      offset += (inserted - main.begin()) == currJacobsthal + insertedNumbers;
      boundIt = main.begin() + (currJacobsthal + insertedNumbers - offset);
    }
    prevJacobsthal = currJacobsthal;
    insertedNumbers += jacobsthalDiff;
    offset = 0;
  }

  /* Insert the remaining elements in the reversed order. Here we also want to
     perform as less comparisons as possible, so we calculate the starting bound
     to insert pend number to be the pair of the first pend number. If the first
     pend number is b8, the bound is a8, if the pend number is b7, the bound is
     a7 etc. With the way I do it the index of bound is size_of_main -
     size_of_pend + index_of_current_pend. */
  for (ssize_t i = pend.size() - 1; i >= 0; i--) {
    typename std::vector<Iterator>::iterator currPend = pend.begin() + i;
    typename std::vector<Iterator>::iterator currBound =
        main.begin() + (main.size() - pend.size() + i + isOdd);
    typename std::vector<Iterator>::iterator idx =
        std::upper_bound(main.begin(), currBound, *currPend, compare<Iterator>);
    main.insert(idx, *currPend);
  }

  /* Use copy vector to store all the numbers, in order not to overwrite the
     original iterators. */
  std::vector<int> copy;
  copy.reserve(container.size());
  for (typename std::vector<Iterator>::iterator it = main.begin();
       it != main.end(); it++) {
    for (int i = 0; i < level; i++) {
      Iterator pairStart = *it;
      std::advance(pairStart, -level + i + 1);
      copy.insert(copy.end(), *pairStart);
    }
  }

  /* Replace values in the original container. */
  Iterator containerIt = container.begin();
  std::vector<int>::iterator copyIt = copy.begin();
  while (copyIt != copy.end()) {
    *containerIt = *copyIt;
    containerIt++;
    copyIt++;
  }
}
