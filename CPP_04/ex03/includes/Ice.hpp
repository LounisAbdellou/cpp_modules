#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(const std::string &type);
  Ice(const Ice &src);
  virtual ~Ice() {}

  Ice &operator=(const Ice &src);

  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};
