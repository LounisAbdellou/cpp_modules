#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	float ab = Point::Vector(a, b, p);
	float bc = Point::Vector(b, c, p);
	float ca = Point::Vector(c, a, p);

	if ((ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0))
		return true;
	return false;
}
