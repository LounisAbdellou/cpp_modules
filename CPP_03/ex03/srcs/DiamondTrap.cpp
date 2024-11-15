#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
  std::cout << "Basic DiamondTrap got created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
  this->_name = name;
  this->_hitPoints = FragTrap::_hitPoints;
  this->_energyPoints = ScavTrap::_energyPoints;
  this->_attackDamage = FragTrap::_attackDamage;

  std::cout << "DiamondTrap " << this->_name << " got created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
    : ClapTrap(src), ScavTrap(src), FragTrap(src) {
  *this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
  if (this == &src)
    return *this;

  this->_name = src.getName();
  this->_hitPoints = src.getHitPoints();
  this->_energyPoints = src.getEnergyPoints();
  this->_attackDamage = src.getAttackDamage();

  return *this;
}

void DiamondTrap::whoAmI() {
  std::cout << "My name is " << this->_name << " but my ClapTrap name is "
            << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << this->_name << " disappeared misteriously"
            << std::endl;
}
