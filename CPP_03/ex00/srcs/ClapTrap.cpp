#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
  this->_name = name;
  this->_hitPoints = 10;
  this->_energyPoints = 10;
  this->_attackDamage = 0;

  std::cout << "ClapTrap " << this->_name << " got created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) { *this = src; }

ClapTrap &ClapTrap::operator=(ClapTrap const &src) {
  if (this == &src)
    return *this;

  this->_hitPoints = src._hitPoints;
  this->_energyPoints = src._energyPoints;
  this->_attackDamage = src._attackDamage;

  return *this;
}

void ClapTrap::attack(const std::string &target) {
  if (this->_energyPoints < 1) {
    std::cout << this->_name << "is exhausted" << std::endl;
    return;
  }

  this->_energyPoints -= 1;

  std::cout << "ClapTrap " << this->_name << " attacks " << target
            << ", causing " << this->_attackDamage << " points of damage!"
            << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  this->_hitPoints -= amount;

  std::cout << "ClapTrap " << this->_name << " sustained -" << amount
            << " points of damage (" << this->_hitPoints << " HP)" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->_energyPoints < 1) {
    std::cout << this->_name << "is exhausted" << std::endl;
    return;
  }

  this->_hitPoints += amount;
  this->_energyPoints -= 1;

  std::cout << "ClapTrap " << this->_name << " got healed +" << amount
            << " points (" << this->_hitPoints << " HP)" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << this->_name << " got destroyed" << std::endl;
}
