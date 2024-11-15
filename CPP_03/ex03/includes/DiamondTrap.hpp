#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
  std::string _name;

public:
  DiamondTrap();
  DiamondTrap(std::string name);
  DiamondTrap(const DiamondTrap &src);
  ~DiamondTrap();

  DiamondTrap &operator=(const DiamondTrap &src);

  void whoAmI();
};

#endif // !DIAMONDTRAP_HPP
