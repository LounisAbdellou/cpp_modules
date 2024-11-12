#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed {
	private:
		int					n;
		static int const	_bits = 8;

	public:
		Fixed();
		Fixed(int n);
		Fixed(float f);
		Fixed(const Fixed& fixed);

		Fixed& operator=(const Fixed& fixed);

		Fixed operator+(const Fixed& fixed);
		Fixed operator-(const Fixed& fixed);
		Fixed operator*(const Fixed& fixed);
		Fixed operator/(const Fixed& fixed);

		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);
	
		bool operator<(const Fixed& fixed);
		bool operator>(const Fixed& fixed);
		bool operator<=(const Fixed& fixed);
		bool operator>=(const Fixed& fixed);
		bool operator==(const Fixed& fixed);
		bool operator!=(const Fixed& fixed);

		int	toInt() const;
		float toFloat() const;
		int	getRawBits() const;	
		void setRawBits(int const raw);

		static Fixed min(Fixed& a, Fixed& b);
		static Fixed max(Fixed& a, Fixed& b);
		static Fixed min(const Fixed& a, const Fixed& b);
		static Fixed max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, Fixed const& fixed);

#endif // !FIXED_HPP
