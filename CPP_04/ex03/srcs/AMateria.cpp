#include "AMateria.hpp"

AMateria::AMateria() { this->_type = "default"; }

AMateria::AMateria(const std::string &type) { this->_type = type; }

AMateria::AMateria(const AMateria &src) { *this = src; }

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &src) {
  if (this == &src)
    return *this;

  this->_type = src.getType();

  return *this;
}

const std::string &AMateria::getType() const { return this->_type; }

void AMateria::use(ICharacter &target) { (void)target; }
