#include "Ice.hpp"
#include "Character.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") { this->_type = "ice"; }

Ice::Ice(const std::string &type) : AMateria(type) { this->_type = type; }

Ice::Ice(const Ice &src) : AMateria(src) { *this = src; }

Ice &Ice::operator=(const Ice &src) {
  if (this == &src)
    return *this;

  this->_type = src.getType();

  return *this;
}

AMateria *Ice::clone() const {
  AMateria *clone = new Ice(*this);

  return clone;
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
