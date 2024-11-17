#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
  std::cout << "WrongCat copy constructor called" << std::endl;

  *this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
  if (this == &src)
    return *this;

  this->_type = src.getType();

  return *this;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor of type called" << std::endl;
}

void WrongCat::makeSound() const {
  std::cout << "ScoobidyPoo WoopDiScoop DiPoo" << std::endl;
}
