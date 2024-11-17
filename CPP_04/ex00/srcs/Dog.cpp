#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
  std::cout << "Dog copy constructor called" << std::endl;

  *this = src;
}

Dog &Dog::operator=(const Dog &src) {
  if (this == &src)
    return *this;

  this->_type = src.getType();

  return *this;
}

Dog::~Dog() { std::cout << "Dog destructor of type called" << std::endl; }

void Dog::makeSound() const { std::cout << "Waouuf :3" << std::endl; }
