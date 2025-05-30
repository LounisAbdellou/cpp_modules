#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap(std::string name);
  FragTrap(const FragTrap &src);
  ~FragTrap();

  FragTrap &operator=(const FragTrap &src);

  void highFivesGuys();
};

#endif // !FRAGTRAP_HPP
