#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
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
  han->attack("Palpatine");
  han->takeDamage(70);

  std::cout << std::endl;

  FragTrap *yoda = new FragTrap("Yoda");

  yoda->attack("Palpatine");
  std::cout << "Palpatine got defeated" << std::endl;
  yoda->highFivesGuys();
  delete yoda;

  std::cout << std::endl;

  han->guardGate();
  delete han;

  std::cout << std::endl;

  DiamondTrap *jack = new DiamondTrap("Jack");

  jack->attack("himself");
  jack->takeDamage(30);
  jack->whoAmI();
  delete jack;

  return 0;
}
