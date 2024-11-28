#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename t> void swap(t &a, t &b) {
  t tmp = a;
  a = b;
  b = tmp;
}

template <typename t> t min(t a, t b) {
  if (a < b)
    return a;
  return b;
}

template <typename t> t max(t a, t b) {
  if (a > b)
    return a;
  return b;
}

#endif // !WHATEVER_HPP
