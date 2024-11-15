#include "ClapTrap.hpp"

ClapTrap::ClapTrap() { std::cout << "Basic Claptrap got created" << std::endl; }

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

std::string ClapTrap::getName() const { return this->_name; }

int ClapTrap::getHitPoints() const { return this->_hitPoints; }

int ClapTrap::getEnergyPoints() const { return this->_energyPoints; }

int ClapTrap::getAttackDamage() const { return this->_attackDamage; }

void ClapTrap::setName(std::string name) { this->_name = name; }

void ClapTrap::setHitPoints(int hitPoints) { this->_hitPoints = hitPoints; }

void ClapTrap::setEnergyPoints(int energyPoints) {
  this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage) {
  this->_attackDamage = attackDamage;
}
