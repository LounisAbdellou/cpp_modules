#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _inventoryMax(4), _groundMax(50) {
  this->_name = "default";
  for (int i = 0; i < _groundMax; i++)
    this->_ground[i] = NULL;
  for (int i = 0; i < _inventoryMax; i++)
    this->_inventory[i] = NULL;
}

Character::Character(const std::string &name)
    : _inventoryMax(4), _groundMax(50) {
  this->_name = name;

  for (int i = 0; i < _groundMax; i++)
    this->_ground[i] = NULL;

  for (int i = 0; i < _inventoryMax; i++)
    this->_inventory[i] = NULL;
}

Character::Character(const Character &src) : _inventoryMax(4), _groundMax(50) {
  *this = src;
}

Character::~Character() {
  for (int i = 0; i < _groundMax; i++)
    if (this->_ground[i] != NULL)
      delete this->_ground[i];

  for (int i = 0; i < _inventoryMax; i++)
    if (this->_inventory[i] != NULL)
      delete this->_inventory[i];
}

Character &Character::operator=(const Character &src) {
  if (this == &src)
    return *this;

  this->_name = src._name;

  for (int i = 0; i < _groundMax; i++)
    *this->_ground[i] = *src._ground[i];

  for (int i = 0; i < _inventoryMax; i++)
    *this->_inventory[i] = *src._inventory[i];

  return *this;
}

const std::string &Character::getName() const { return this->_name; }

int Character::findSlot(AMateria **tab, AMateria *m, int size) const {
  int index = -1;

  for (int i = 0; i < size; i++) {
    if (tab[i] == NULL && index == -1)
      index = i;
    else if (tab[i] == m)
      return -1;
  }

  return index;
}

void Character::equip(AMateria *m) {
  const int index = this->findSlot(this->_inventory, m, _inventoryMax);
  const int groundIndex = this->findSlot(this->_ground, m, _groundMax);
  if (index < 0 || groundIndex < 0)
    return;

  this->_inventory[index] = m;
}

void Character::unequip(int idx) {
  AMateria *m = this->_inventory[idx];
  const int index = this->findSlot(this->_ground, m, _groundMax);
  if (this->_inventory[idx] == NULL || index < 0)
    return;

  this->_ground[index] = this->_inventory[idx];
  this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  if (this->_inventory[idx] == NULL)
    return;

  this->_inventory[idx]->use(target);
}
