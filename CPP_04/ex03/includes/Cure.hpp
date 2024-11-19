#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(const std::string &type);
  Cure(const Cure &src);
  virtual ~Cure() {}

  Cure &operator=(const Cure &src);

  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};
