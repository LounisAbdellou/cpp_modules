#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		const Fixed			x;
		const Fixed			y;

	public:
		Point();
		Point(const Point& point);
		Point(const float x, const float y);
		~Point();

		Point				operator=(const Point& point);
		
		float				getPosX() const;
		float				getPosY() const;
		void				setPosX(float x);
		void				setPosY(float y);
		static float		Vector(const Point& u, const Point& v, const Point& p);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif // !POINT_HPP
