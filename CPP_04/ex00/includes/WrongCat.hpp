#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
private:
  std::string _type;

public:
  WrongCat();
  WrongCat(const WrongCat &src);
  ~WrongCat();

  WrongCat &operator=(const WrongCat &src);

  void makeSound() const;
};

#endif // !WRONGCAT_HPP
