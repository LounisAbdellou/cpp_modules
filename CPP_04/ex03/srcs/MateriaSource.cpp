#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() : _stockMax(4) {
  this->_stockIndex = 0;
  for (int i = 0; i < this->_stockMax; i++)
    this->_stock[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) : _stockMax(4) {
  *this = src;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < this->_stockMax; i++)
    delete this->_stock[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
  if (this == &src)
    return *this;

  this->_stockIndex = src._stockIndex;
  for (int i = 0; i < this->_stockMax; i++)
    *this->_stock[i] = *src._stock[i];

  return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
  if (this->_stockIndex >= _stockMax)
    return;

  this->_stock[this->_stockIndex++] = m;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  for (int i = 0; i < this->_stockMax; i++) {
    if (this->_stock[i] && this->_stock[i]->getType() == type)
      return this->_stock[i]->clone();
  }

  return 0;
}
