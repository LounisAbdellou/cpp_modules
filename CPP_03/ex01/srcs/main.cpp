#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  ClapTrap *luke = new ClapTrap("Luke");
  ScavTrap *han = new ScavTrap("Han");

  std::cout << std::endl;

  luke->attack("Anakin");
  luke->takeDamage(7);
  luke->beRepaired(3);
  luke->takeDamage(7);

  delete luke;

  std::cout << std::endl;

  han->attack("Anakin");
  han->takeDamage(7);
  han->beRepaired(10);
  han->takeDamage(7);
  han->attack("Anakin");
  std::cout << "Anakin got defeated" << std::endl;

  std::cout << std::endl;

  han->guardGate();

  delete han;

  return 0;
}
