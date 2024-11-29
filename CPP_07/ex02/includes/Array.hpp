#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <class T> class Array {
private:
  T *_array;
  unsigned int _size;

public:
  Array() {
    this->_size = 0;
    this->_array = new T[0];
  }

  Array(const Array &src) {
    this->_size = 0;
    this->_array = new T[0];
    *this = src;
  }

  Array(unsigned int n) {
    this->_size = n;
    this->_array = new T[n];

    for (unsigned int i = 0; i < n; i++) {
      this->_array[i] = 0;
    }
  }

  ~Array() { delete[] this->_array; }

  Array &operator=(const Array &src) {
    if (this == &src)
      return *this;

    delete[] this->_array;
    this->_size = src._size;
    this->_array = new T[src._size];

    for (unsigned int i = 0; i < src._size; i++)
      this->_array[i] = src._array[i];

    return *this;
  }

  const T &operator[](unsigned int i) const {
    if (i >= this->_size)
      throw Array<T>::OutOfBoundException();

    return this->_array[i];
  }

  T &operator[](unsigned int i) {
    if (i >= this->_size)
      throw Array<T>::OutOfBoundException();

    return this->_array[i];
  }

  unsigned int size() const { return this->_size; }

  class OutOfBoundException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "The index is out of bound.";
    }
  };
};

#endif // !ARRAY_HPP
