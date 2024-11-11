#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "This is a DEBUG message" << std::endl;
}

void Harl::info()
{
	std::cout << PURPLE << "This is an INFO message";
	std::cout << WHITE << std::endl;
}

void Harl::warning()
{
	std::cout << YELLOW << "This is a WARNING message";
	std::cout << WHITE << std::endl;
}

void Harl::error()
{
	std::cout << RED << "This is an ERROR message";
	std::cout << WHITE << std::endl;
}

Harl::Harl()
{
	this->levels[0].key = "DEBUG";
	this->levels[0].func = &Harl::debug;

	this->levels[1].key = "INFO";
	this->levels[1].func = &Harl::info;

	this->levels[2].key = "WARNING";
	this->levels[2].func = &Harl::warning;

	this->levels[3].key = "ERROR";
	this->levels[3].func = &Harl::error;
}

int Harl::isStored(std::string level)
{
	for (size_t i = 0; i < 4; i++)
		if (!std::strcmp(this->levels[i].key.c_str(), level.c_str()))
			return 1;

	return 0;
}

void Harl::complain(std::string level)
{
	size_t start = 0;

	if (!this->isStored(level))
	{
		std::cout << "Level does not exist" << std::endl;
		return;
	}

	switch (level[0]) {
		case 'D': 
			start = 0;
			break;
		case 'I': 
			start = 1;
			break;
		case 'W': 
			start = 2;
			break;
		case 'E': 
			start = 3;
			break;
		default:
			break;
	}

	for (size_t i = start; i < 4; i++)
		(this->*(this->levels[i].func))();
}
