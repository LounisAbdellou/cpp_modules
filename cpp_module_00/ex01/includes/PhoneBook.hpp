#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "module.h"
# include "Contact.hpp"

class PhoneBook {
	private:
		int		currentIndex;
		Contact contacts[BOOK_SIZE];
		void	printRow(std::string cols[4], bool isLast);
		void	printSeparator(bool isExtreme);
	public:
		PhoneBook();
		void	addContact();
		void	searchContact();
};

#endif // !PHONEBOOK_HPP
