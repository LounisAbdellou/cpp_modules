#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "module.h"

PhoneBook::PhoneBook() { this->currentIndex = 0; }

void PhoneBook::addContact() {
  std::string input;
  Contact newContact;

  while (1) {
    if (std::cin.eof())
      break;
    if (newContact.getFirstName().empty()) {
      std::cout << "Enter firstname : ";
      std::getline(std::cin, input);
      newContact.setFirstName(input);
    } else if (newContact.getLastName().empty()) {
      std::cout << "Enter lastname : ";
      std::getline(std::cin, input);
      newContact.setLastName(input);
    } else if (newContact.getNickName().empty()) {
      std::cout << "Enter nickname : ";
      std::getline(std::cin, input);
      newContact.setNickName(input);
    } else if (newContact.getPhoneNumber().empty()) {
      std::cout << "Enter phone number : ";
      std::getline(std::cin, input);
      newContact.setPhoneNumber(input);
    } else if (newContact.getSecret().empty()) {
      std::cout << "Enter darkest secret : ";
      std::getline(std::cin, input);
      newContact.setSecret(input);
    } else {
      std::cout << GREEN << "contact successfully created\n";
      this->contacts[this->currentIndex++ % BOOK_SIZE] = newContact;
      break;
    }
  }
}

void PhoneBook::printSeparator(bool isExtreme) {
  for (size_t i = 1; i <= 40; i++) {
    if (i == 1)
      std::cout << (isExtreme ? "+" : "|");

    std::cout << "-";

    if (i % 10 == 0)
      std::cout << (i != 40 || isExtreme ? "+" : "|");
  }
  std::cout << std::endl;
}

void PhoneBook::printRow(std::string cols[4], bool isLast) {
  int k;

  for (size_t i = 0; i < 4; i++) {
    k = 0;
    std::cout << "|";
    for (size_t j = 0; j < 10; j++) {
      if (j + cols[i].length() - 1 < 9) {
        std::cout << " ";
        continue;
      }

      if (j == 9 && cols[i].length() > 10)
        std::cout << ".";
      else
        std::cout << cols[i][k++];
    }
  }
  std::cout << "|" << std::endl;
  printSeparator(isLast);
}

void PhoneBook::searchContact() {
  size_t len;
  std::string input;
  std::string cols[4];

  cols[0] = "Index";
  cols[1] = "Firstname";
  cols[2] = "Lastname";
  cols[3] = "Nickname";
  len = this->currentIndex < 8 ? this->currentIndex : 8;
  if (this->currentIndex == 0) {
    std::cout << YELLOW << "your PhoneBook is empty\n";
    return;
  }

  this->printSeparator(1);
  this->printRow(cols, 0);
  for (size_t i = 0; i < len; i++) {
    cols[0] = i + 48;
    cols[1] = this->contacts[i].getFirstName();
    cols[2] = this->contacts[i].getLastName();
    cols[3] = this->contacts[i].getNickName();
    this->printRow(cols, i == len - 1);
  }

  while (1) {
    std::cout << "Enter contact index : ";
    std::getline(std::cin, input);

    if (std::cin.eof())
      break;

    if (input[0] > (this->currentIndex - 1) + 48 || input[0] < 48)
      std::cout << RED << "this index do not exist\n\n" << WHITE;
    else {
      std::cout << "Firstname : ";
      std::cout << this->contacts[input[0] - 48].getFirstName() << std::endl;

      std::cout << "Lastname : ";
      std::cout << this->contacts[input[0] - 48].getLastName() << std::endl;

      std::cout << "Nickname : ";
      std::cout << this->contacts[input[0] - 48].getNickName() << std::endl;

      std::cout << "Phone : ";
      std::cout << this->contacts[input[0] - 48].getPhoneNumber() << std::endl;

      std::cout << "Darkest Secret : ";
      std::cout << this->contacts[input[0] - 48].getSecret() << std::endl;
      break;
    }
  }
}
