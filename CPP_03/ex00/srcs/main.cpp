#include "ClapTrap.hpp"

int main() {
  ClapTrap *luke = new ClapTrap("Luke");

  luke->attack("Anakin");
  luke->takeDamage(7);
  luke->beRepaired(3);
  luke->takeDamage(7);

  delete luke;

  return 0;
}
