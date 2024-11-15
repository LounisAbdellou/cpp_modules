#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "Basic Scavtrap got created" << std::endl;

  this->_energyPoints = 50;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap() {
  this->_name = name;
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;

  std::cout << "ScavTrap " << this->_name << " got created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src.getName()) {
  *this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
  if (this == &src)
    return *this;

  this->_name = src.getName();
  this->_hitPoints = src.getHitPoints();
  this->_energyPoints = src.getEnergyPoints();
  this->_attackDamage = src.getAttackDamage();

  return *this;
}

void ScavTrap::attack(const std::string &target) {
  if (this->getEnergyPoints() < 1) {
    std::cout << this->_name << "is exhausted" << std::endl;
    return;
  }

  this->_energyPoints -= 1;

  std::cout << "ScavTrap " << this->_name << " attacks " << target
            << ", causing " << this->_attackDamage << " points of damage!"
            << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << this->_name << " has started guarding the gates" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << this->_name << " got retired" << std::endl;
}
