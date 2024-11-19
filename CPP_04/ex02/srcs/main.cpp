#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const Dog *j = new Dog();
  const Cat *i = new Cat();

  std::cout << std::endl;

  std::cout << j->getType() << std::endl;
  j->makeSound();

  std::cout << std::endl;

  std::cout << i->getType() << std::endl;
  i->makeSound();

  std::cout << std::endl;

  delete i;
  delete j;

  return 0;
}
