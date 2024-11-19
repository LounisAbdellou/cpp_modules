#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
  Brain *brain;
  std::string _type;

public:
  Dog();
  Dog(const Dog &src);
  virtual ~Dog();

  Dog &operator=(const Dog &src);

  void makeSound() const;
};

#endif // !DOG_HPP
