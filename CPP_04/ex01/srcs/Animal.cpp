#include "Animal.hpp"

Animal::Animal() {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) {
  std::cout << "Animal parameterized constructor of type " << type << " called"
            << std::endl;

  this->_type = type;
}

Animal::Animal(const Animal &src) {
  std::cout << "Animal copy constructor called" << std::endl;

  *this = src;
}

Animal &Animal::operator=(const Animal &src) {
  if (this == &src)
    return *this;

  this->_type = src.getType();

  return *this;
}

Animal::~Animal() {
  std::cout << "Animal destructor of type (" << this->_type << ") called"
            << std::endl;
}

std::string Animal::getType() const { return this->_type; }

void Animal::makeSound() const {
  std::cout << "Weird undiscernible grunt ..." << std::endl;
}
