#include "AMateria.hpp"
#include <Character.hpp>
#include <Cure.hpp>
#include <Ice.hpp>
#include <MateriaSource.hpp>

int main() {
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter *me = new Character("me");

  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter *bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  me->unequip(0);
  me->unequip(1);

  me->use(0, *bob);
  me->use(1, *bob);

  me->equip(src->createMateria("cure"));
  me->equip(src->createMateria("ice"));

  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;

  return 0;
}
