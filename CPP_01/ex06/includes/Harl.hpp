#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <cstring>

# define RED "\033[0;31m"
# define PURPLE "\e[0;35m"
# define YELLOW "\e[1;33m"
# define WHITE "\033[0m"

class Harl {
	typedef struct s_levels
	{
		std::string		key;
		void			(Harl::* func)(void);
	}	t_levels;

	private:
		t_levels	levels[4];
		void		debug();
		void		info();
		void		warning();
		void		error();
		int			isStored(std::string level);

	public:
		Harl();
		void		complain(std::string level);
};

#endif // !HARL_HPP
