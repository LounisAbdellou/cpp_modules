#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << std::endl;

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;

  i->makeSound();
  j->makeSound();
  meta->makeSound();

  std::cout << std::endl;

  delete meta;
  delete j;
  delete i;

  std::cout << std::endl;

  const WrongAnimal *wtf = new WrongAnimal();
  const WrongAnimal *wtheck = new WrongCat();

  std::cout << std::endl;

  wtf->makeSound();
  wtheck->makeSound();

  std::cout << std::endl;

  delete wtf;
  delete wtheck;

  return 0;
}
