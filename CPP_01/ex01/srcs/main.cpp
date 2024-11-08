#include "Zombie.hpp"

int main()
{
	int		N;
	Zombie* zombies;

	N = 3;
	zombies = zombieHorde(N, "John");
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete [] zombies;
	
	return 0;
}
