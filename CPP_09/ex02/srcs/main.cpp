#include <PmergeMe.hpp>
#include <iostream>

int main(int ac, char **av) {
  if (ac < 2) {
    std::cout << "Error: wrong number of arguments" << std::endl;

    return 1;
  }

  try {
    PmergeMe merge(ac - 1, av += 1);

    merge.printState("Before: ");
    merge.sortVector();
    merge.printState("After:  ");
  } catch (const std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}
