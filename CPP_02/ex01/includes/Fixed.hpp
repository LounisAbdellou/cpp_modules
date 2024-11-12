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

		int					toInt() const;
		float				toFloat() const;
		int					getRawBits() const;	
		void				setRawBits(int const raw);

		~Fixed();
};

std::ostream& operator<<(std::ostream& out, Fixed const& fixed);

#endif // !FIXED_HPP
