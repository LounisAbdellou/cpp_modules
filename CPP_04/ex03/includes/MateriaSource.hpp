#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>

class AMateria;

class IMateriaSource {
public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria *m) = 0;
  virtual AMateria *createMateria(const std::string &type) = 0;
};

class MateriaSource : public IMateriaSource {
private:
  AMateria *_stock[4];
  const int _stockMax;
  int _stockIndex;

public:
  MateriaSource();
  MateriaSource(const MateriaSource &src);
  ~MateriaSource();

  MateriaSource &operator=(const MateriaSource &src);

  virtual void learnMateria(AMateria *m);
  virtual AMateria *createMateria(const std::string &type);
};

#endif // !MATERIASOURCE_HPP
