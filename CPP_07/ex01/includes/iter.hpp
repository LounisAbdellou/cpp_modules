#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>

template <typename t> void iter(t *array, size_t length, void (*func)(t &)) {
  for (size_t i = 0; i < length; i++) {
    func(array[i]);
  }
}

#endif // !ITER_HPP
