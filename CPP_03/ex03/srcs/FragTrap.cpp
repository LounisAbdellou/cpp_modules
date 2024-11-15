#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  std::cout << "Basic Fragtrap got created" << std::endl;

  this->_hitPoints = 100;
  this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap() {
  this->_name = name;
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;

  std::cout << "FragTrap " << this->_name << " appeared out of no where"
            << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src.getName()) {
  *this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &src) {
  if (this == &src)
    return *this;

  this->_name = src.getName();
  this->_hitPoints = src.getHitPoints();
  this->_energyPoints = src.getEnergyPoints();
  this->_attackDamage = src.getAttackDamage();

  return *this;
}

void FragTrap::highFivesGuys() {
  std::cout << this->_name << " high fived his boys" << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << this->_name << " disappeared in the sunset"
            << std::endl;
}
