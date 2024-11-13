#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& point) : x(point.getPosX()), y(point.getPosY()) {}

Point::~Point() {}

Point Point::operator=(const Point& point)
{
	if (this == &point)
		return *this;

	return Point(point);
}

float Point::getPosX() const
{
	return this->x.toFloat();
}

float Point::getPosY() const
{
	return this->y.toFloat();
}

float Point::Vector(const Point& u, const Point& v, const Point& p)
{
	return (v.getPosX() - u.getPosX()) * (p.getPosY() - u.getPosY()) - (v.getPosY() - u.getPosY()) * (p.getPosX() - u.getPosX());
} 
