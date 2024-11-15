#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;

public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &src);
  ~ClapTrap();

  ClapTrap &operator=(const ClapTrap &src);

  std::string getName() const;
  int getHitPoints() const;
  int getEnergyPoints() const;
  int getAttackDamage() const;

  void setName(std::string name);
  void setHitPoints(int hitPoints);
  void setEnergyPoints(int energyPoints);
  void setAttackDamage(int attackDamage);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif // !CLAPTRAP_HPP
