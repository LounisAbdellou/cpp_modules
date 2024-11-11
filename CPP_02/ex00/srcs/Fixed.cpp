#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed* Fixed::operator=(Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());

	return this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->number;
}

void Fixed::setRawBits(int const raw)
{
	this->number = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
