#include "Contact.hpp"
#include "module.h"

bool Contact::isAllNum(std::string str) {
  for (size_t i = 0; i < str.length(); i++) {
    if (!std::isdigit(str[i]))
      return false;
  }

  return true;
}

bool Contact::isAllAlpha(std::string str) {
  for (size_t i = 0; i < str.length(); i++) {
    if (!std::isalpha(str[i]))
      return false;
  }

  return true;
}

std::string Contact::getFirstName() { return this->firstName; }

std::string Contact::getLastName() { return this->lastName; }

std::string Contact::getNickName() { return this->nickName; }

std::string Contact::getPhoneNumber() { return this->phoneNumber; }

std::string Contact::getSecret() { return this->secret; }

void Contact::setFirstName(std::string firstName) {
  if (!this->isAllAlpha(firstName)) {
    std::cout << RED << "Firstname must only contain letters";
    std::cout << WHITE << std::endl;
    return;
  }

  this->firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
  if (!this->isAllAlpha(lastName)) {
    std::cout << RED << "Lastname must only contain letters";
    std::cout << WHITE << std::endl;
    return;
  }

  this->lastName = lastName;
}

void Contact::setNickName(std::string nickName) {
  if (nickName.empty())
    return;

  this->nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
  if (!this->isAllNum(phoneNumber))
  {
  	std::cout << RED << "Phone number must only contain digits";
  	std::cout << WHITE << std::endl;
  	return;
  }
  else if (phoneNumber.length() != 10)
  {
  	std::cout << RED << "Phone number must have a length of 10 digits";
  	std::cout << WHITE << std::endl;
  	return;
  }

  this->phoneNumber = phoneNumber;
}

void Contact::setSecret(std::string secret) {
  if (secret.empty())
    return;

  this->secret = secret;
}
