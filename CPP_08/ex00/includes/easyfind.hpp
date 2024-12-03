#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T> void easyfind(T container, int n) {
  typename T::iterator it;

  it = std::find(container.begin(), container.end(), n);

  if (*it == n) {
    std::cout << n << " was found inside the container !" << std::endl;
    return;
  }

  throw std::invalid_argument("occurrence was not found.");
}

#endif // !EASYFIND_HPP
