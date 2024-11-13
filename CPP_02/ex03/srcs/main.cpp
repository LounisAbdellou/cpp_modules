#include "Point.hpp"

int main()
{
	Point const a(10, 10);
	Point const b(0, 20);
	Point const c(20, 20);
	Point const d(10, 15);

	if (bsp(a, b, c, d))
		std::cout << "Point is inside" << std::endl;
	else
		std::cout << "Point is outside" << std::endl;

	return 0;
}
