#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
  std::cout << "WrongAnimal parameterized constructor of type " << type
            << " called" << std::endl;

  this->_type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;

  *this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
  if (this == &src)
    return *this;

  this->_type = src.getType();

  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor of type (" << this->_type << ") called"
            << std::endl;
}

std::string WrongAnimal::getType() const { return this->_type; }

void WrongAnimal::makeSound() const {
  std::cout << "Bum biddy biddy biddy bum bum" << std::endl;
}
