#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class AMateria;

class ICharacter {
public:
  virtual ~ICharacter() {}
  virtual const std::string &getName() const = 0;
  virtual void equip(AMateria *m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter &target) = 0;
};

class Character : public ICharacter {
private:
  std::string _name;
  AMateria *_inventory[4];
  AMateria *_ground[50];
  const int _inventoryMax;
  const int _groundMax;

public:
  Character();
  Character(const std::string &name);
  Character(const Character &src);
  virtual ~Character();

  Character &operator=(const Character &src);

  virtual const std::string &getName() const;

  int findSlot(AMateria **tab, AMateria *m, int size) const;
  virtual void equip(AMateria *m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter &target);
};

#endif // !CHARACTER_HPP
