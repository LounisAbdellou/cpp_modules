#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	std::string weaponType = this->weapon->getType();

	std::cout << this->name << " attacks with their " << weaponType;
	std::cout << std::endl;
}
