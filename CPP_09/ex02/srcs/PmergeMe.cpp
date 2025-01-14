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
  T start = next(it, -pair_level + 1);
  T end = next(start, pair_level);
  while (start != end) {
    std::iter_swap(start, next(start, pair_level));
    start++;
  }
}

template <typename t> void PmergeMe::_sortContainer(t &container, int level) {
  typedef typename t::iterator Iterator;

  int pair_units_nbr = container.size() / level;
  if (pair_units_nbr < 2)
    return;

  /* If there is an odd pair, we ignore it during swapping.
     It will go to the pend as the last pair. */
  bool is_odd = pair_units_nbr % 2 == 1;

  /* It's important to caluclate the end position until which we should iterate.
     We can have a set of values like:
     ((1 2) (3 4)) ((3 8) (2 6)) | 0
     where there are numbers (0 in this case) which can't even form a pair.
     Those values should be ignored. */
  Iterator start = container.begin();
  Iterator last = next(container.begin(), level * (pair_units_nbr));
  Iterator end = next(last, -(is_odd * level));

  /* Swap pairs of numbers, pairs, pairs of pairs etc by the biggest pair
     number. After each swap we recurse. */
  int jump = 2 * level;
  for (Iterator it = start; it != end; std::advance(it, jump)) {
    Iterator this_pair = next(it, level - 1);
    Iterator next_pair = next(it, level * 2 - 1);
    if (compare(next_pair, this_pair)) {
      this->_swapPair(this_pair, level);
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
  main.insert(main.end(), next(container.begin(), level - 1));
  main.insert(main.end(), next(container.begin(), level * 2 - 1));

  /* Insert the rest of a's into the main chain.
     Insert the rest of b's into the pend. */
  for (int i = 4; i <= pair_units_nbr; i += 2) {
    pend.insert(pend.end(), next(container.begin(), level * (i - 1) - 1));
    main.insert(main.end(), next(container.begin(), level * i - 1));
  }

  /* Insert an odd element to the pend, if there are any. */
  if (is_odd) {
    pend.insert(pend.end(), next(end, level - 1));
  }

  /* Insert the pend into the main in the order determined by the
     Jacobsthal numbers. For example: 3 2 -> 5 4 -> 11 10 9 8 7 6 -> etc.
     During insertion, main numbers serve as an upper bound for inserting
     numbers, in order to save number of comparisons, as we know already that,
     for example, b5 is lesser than a5, we binary search only until a5, not
     until the end of the container. We can calculate the index of the bound
     element. With the way I do it, the index of the bound is inserted_numbers +
     current_jacobsthal_number. */
  int prev_jacobsthal = this->_jacobsthalNumber(1);
  int inserted_numbers = 0;
  for (int k = 2;; k++) {
    int curr_jacobsthal = this->_jacobsthalNumber(k);
    int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
    int offset = 0;
    if (jacobsthal_diff > static_cast<int>(pend.size()))
      break;
    int nbr_of_times = jacobsthal_diff;
    typename std::vector<Iterator>::iterator pend_it =
        next(pend.begin(), jacobsthal_diff - 1);
    typename std::vector<Iterator>::iterator bound_it =
        next(main.begin(), curr_jacobsthal + inserted_numbers);
    while (nbr_of_times) {
      typename std::vector<Iterator>::iterator idx =
          std::upper_bound(main.begin(), bound_it, *pend_it, compare<Iterator>);
      typename std::vector<Iterator>::iterator inserted =
          main.insert(idx, *pend_it);
      nbr_of_times--;
      pend_it = pend.erase(pend_it);
      std::advance(pend_it, -1);
      /* Sometimes the inserted number in inserted at the exact index of where
         the bound should be. When this happens, it eclipses the bound of the
         next pend, and it does more comparisons than it should. We need to
         offset when this happens. */
      offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
      bound_it =
          next(main.begin(), curr_jacobsthal + inserted_numbers - offset);
    }
    prev_jacobsthal = curr_jacobsthal;
    inserted_numbers += jacobsthal_diff;
    offset = 0;
  }

  /* Insert the remaining elements in the reversed order. Here we also want to
     perform as less comparisons as possible, so we calculate the starting bound
     to insert pend number to be the pair of the first pend number. If the first
     pend number is b8, the bound is a8, if the pend number is b7, the bound is
     a7 etc. With the way I do it the index of bound is size_of_main -
     size_of_pend + index_of_current_pend. */
  for (ssize_t i = pend.size() - 1; i >= 0; i--) {
    typename std::vector<Iterator>::iterator curr_pend = next(pend.begin(), i);
    typename std::vector<Iterator>::iterator curr_bound =
        next(main.begin(), main.size() - pend.size() + i + is_odd);
    typename std::vector<Iterator>::iterator idx = std::upper_bound(
        main.begin(), curr_bound, *curr_pend, compare<Iterator>);
    main.insert(idx, *curr_pend);
  }

  /* Use copy vector to store all the numbers, in order not to overwrite the
     original iterators. */
  std::vector<int> copy;
  copy.reserve(container.size());
  for (typename std::vector<Iterator>::iterator it = main.begin();
       it != main.end(); it++) {
    for (int i = 0; i < level; i++) {
      Iterator pair_start = *it;
      std::advance(pair_start, -level + i + 1);
      copy.insert(copy.end(), *pair_start);
    }
  }

  /* Replace values in the original container. */
  Iterator container_it = container.begin();
  std::vector<int>::iterator copy_it = copy.begin();
  while (copy_it != copy.end()) {
    *container_it = *copy_it;
    container_it++;
    copy_it++;
  }
}
