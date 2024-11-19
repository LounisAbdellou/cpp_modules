#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") { this->_type = "cure"; }

Cure::Cure(const std::string &type) : AMateria(type) { this->_type = type; }

Cure::Cure(const Cure &src) : AMateria(src) { *this = src; }

Cure &Cure::operator=(const Cure &src) {
  if (this == &src)
    return *this;

  this->_type = src.getType();

  return *this;
}

AMateria *Cure::clone() const {
  AMateria *clone = new Cure(*this);

  return clone;
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
