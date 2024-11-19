#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog default constructor called" << std::endl;

  this->brain = new Brain();
  this->brain->addIdeas("Eating");
  this->brain->addIdeas("Sleeping");
  this->brain->addIdeas("Chewing Bone");
}

Dog::Dog(const Dog &src) : Animal(src) {
  std::cout << "Dog copy constructor called" << std::endl;

  *this = src;
}

Dog &Dog::operator=(const Dog &src) {
  if (this == &src)
    return *this;

  this->_type = src.getType();

  return *this;
}

Dog::~Dog() {
  std::cout << "Dog destructor of type called" << std::endl;

  delete this->brain;
}

void Dog::makeSound() const { std::cout << "Waouuf :3" << std::endl; }
