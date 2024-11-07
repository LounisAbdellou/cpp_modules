#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "module.h"

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string secret;
		bool		isAllNum(std::string str);
		bool		isAllAlpha(std::string str);
	public:
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getSecret();
		void		setFirstName(std::string firstName);
		void		setLastName(std::string lastName);
		void		setNickName(std::string nickName);
		void		setSecret(std::string secret);
		void		setPhoneNumber(std::string phoneNumber);

};

#endif // !CONTACT_HPP
