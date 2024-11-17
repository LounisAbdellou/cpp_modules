#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
  std::string _type;

public:
  WrongAnimal();
  WrongAnimal(std::string type);
  WrongAnimal(const WrongAnimal &src);
  virtual ~WrongAnimal();

  WrongAnimal &operator=(const WrongAnimal &src);

  std::string getType() const;

  void makeSound() const;
};

#endif // !WRONGANIMAL_HPP
