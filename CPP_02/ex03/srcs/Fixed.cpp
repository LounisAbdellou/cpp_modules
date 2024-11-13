#include "Fixed.hpp"

Fixed::Fixed()
{
	this->n = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

Fixed::Fixed(int n)
{
	this->n = n << Fixed::_bits;
}

Fixed::Fixed(float f)
{
	this->n = roundf(f * (1 << Fixed::_bits));
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	if (this == &fixed)
		return *this;

	this->setRawBits(fixed.getRawBits());

	return *this;
}

bool  Fixed::operator<(const Fixed& fixed)
{
	if (this->n < fixed.n)
		return true;
	return false;
}

bool  Fixed::operator>(const Fixed& fixed)
{
	if (this->n > fixed.n)
		return true;
	return false;
}

bool  Fixed::operator<=(const Fixed& fixed)
{
	if (this->n <= fixed.n)
		return true;
	return false;
}

bool  Fixed::operator>=(const Fixed& fixed)
{
	if (this->n >= fixed.n)
		return true;
	return false;
}

bool  Fixed::operator==(const Fixed& fixed)
{
	if (this->n == fixed.n)
		return true;
	return false;
}

bool  Fixed::operator!=(const Fixed& fixed)
{
	if (this->n != fixed.n)
		return true;
	return false;
}

float Fixed::operator+(const Fixed& fixed)
{
	Fixed res;

	res.n = this->n + fixed.n;
 
	return res.toFloat();
}

float Fixed::operator-(const Fixed& fixed)
{
	Fixed res;

	res.n = this->n - fixed.n;
 
	return res.toFloat();
}

float Fixed::operator*(const Fixed& fixed)
{
	Fixed res;

	res.n = (this->n * fixed.n) / (1 << Fixed::_bits);
 
	return res.toFloat();
}

float Fixed::operator/(const Fixed& fixed)
{
	Fixed res;

	if (this->n < 1 || fixed.n < 1)
		return res.toFloat();
	res.n = (this->n / fixed.n) * (1 << Fixed::_bits);
 
	return res.toFloat();
}

Fixed& Fixed::operator++()
{
	this->n++;

	return *this;
}

Fixed& Fixed::operator--()
{
	this->n--;

	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);

	operator++();
	
	return copy;
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);

	operator--();
	
	return copy;
}

int Fixed::getRawBits() const
{
	return this->n;
}

void Fixed::setRawBits(int const raw)
{
	this->n = raw;
}

int	Fixed::toInt() const
{
	return this->n >> Fixed::_bits;
}

float Fixed::toFloat() const
{
	return (float)this->n / (float)(1 << Fixed::_bits);
}

Fixed Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return b;
	return a;
}

Fixed Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

Fixed Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

Fixed Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

std::ostream& operator<<(std::ostream& out, Fixed const& fixed)
{
	out << fixed.toFloat();

	return out;
}
