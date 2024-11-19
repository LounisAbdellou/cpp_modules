#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat default constructor called" << std::endl;

  this->brain = new Brain();
  this->brain->addIdeas("Eating");
  this->brain->addIdeas("Sleeping");
  this->brain->addIdeas("Playing with ball of wool");
}

Cat::Cat(const Cat &src) : Animal(src) {
  std::cout << "Cat copy constructor called" << std::endl;

  *this = src;
}

Cat &Cat::operator=(const Cat &src) {
  if (this == &src)
    return *this;

  this->_type = src.getType();

  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor of type called" << std::endl;

  delete this->brain;
}

void Cat::makeSound() const { std::cout << "Miaou :3" << std::endl; }
