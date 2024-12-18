#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
private:
  std::string _type;

public:
  Dog();
  Dog(const Dog &src);
  ~Dog();

  Dog &operator=(const Dog &src);

  void makeSound() const;
};

#endif // !DOG_HPP
