#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const Animal *animals[8];

  for (size_t i = 0; i < 8; i++) {
    if (i % 2 == 0)
      animals[i] = new Dog();
    else
      animals[i] = new Cat();
  }

  std::cout << std::endl << std::endl;

  animals[0]->makeSound();
  animals[1]->makeSound();

  std::cout << std::endl << std::endl;

  for (size_t i = 0; i < 8; i++)
    delete animals[i];

  return 0;
}
