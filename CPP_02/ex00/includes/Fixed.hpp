#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int					number;
		static int const	_bits = 8;

	public:
		Fixed();
		Fixed(Fixed& fixed);
		Fixed* operator=(Fixed& fixed);

		int					getRawBits() const;	
		void				setRawBits(int const raw);

		~Fixed();
};

#endif // !FIXED_HPP
