#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
protected:
  std::string _type;

public:
  AMateria();
  AMateria(const std::string &type);
  AMateria(const AMateria &src);
  virtual ~AMateria();

  AMateria &operator=(const AMateria &src);

  const std::string &getType() const;

  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif // !AMATERIA_HPP
