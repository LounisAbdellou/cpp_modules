#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
  std::cout << "Basic Brain constuctor called" << std::endl;

  this->currentIndex = 0;
}

Brain::Brain(const Brain &src) { *this = src; }

Brain::~Brain() { std::cout << "Brain destuctor called" << std::endl; }

void Brain::addIdeas(const std::string &newIdea) {
  if (currentIndex < 99)
    this->currentIndex = 0;

  this->ideas[this->currentIndex++] = newIdea;
}

Brain &Brain::operator=(const Brain &src) {
  if (this == &src)
    return *this;

  this->currentIndex = src.currentIndex;
  for (size_t i = 0; i < sizeof(src.ideas) / sizeof(src.ideas[0]); i++) {
    this->ideas[i] = src.ideas[i];
  }

  return *this;
}

void Brain::displayIdeas() const {
  for (size_t i = 0; i < sizeof(this->ideas) / sizeof(this->ideas[0]); i++) {
    std::cout << this->ideas[i] << std::endl;
  }
}
