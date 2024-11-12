#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->n = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->n = n << Fixed::_bits;
}

Fixed::Fixed(float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->n = roundf(f * (1 << Fixed::_bits));
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());

	return *this;
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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, Fixed const& fixed)
{
	out << fixed.toFloat();

	return out;
}
