#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
private:
  std::string _type;

public:
  Cat();
  Cat(const Cat &src);
  ~Cat();

  Cat &operator=(const Cat &src);

  void makeSound() const;
};

#endif // !CAT_HPP
