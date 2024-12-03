#include "easyfind.hpp"
#include <deque>
#include <list>
#include <vector>

int main(void) {
  // std::vector<int> container;
  // for (int i = 1; i < 10; i++) {
  //   container.push_back(i);
  // }

  // std::list<int> container;
  // for (int i = 1; i < 10; i++) {
  //   container.push_back(i);
  // }

  std::deque<int> container;
  for (int i = 1; i < 10; i++) {
    container.push_back(i);
  }

  try {
    easyfind(container, 5);
  } catch (const std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}
