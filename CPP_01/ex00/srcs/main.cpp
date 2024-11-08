#include "Zombie.h"

int main()
{
	Zombie* zombie;

	randomChump("John");
	std::cout << std::endl;

	zombie = newZombie("David");
	zombie->announce();
	delete zombie;
}
