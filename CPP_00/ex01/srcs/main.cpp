#include "PhoneBook.hpp"
#include "module.h"

void printDecoration(size_t len, std::string message) {
  for (size_t i = 0; i < (len - message.length()) / 2; i++)
    std::cout << CYAN << "*";

  std::cout << message;

  for (size_t i = 0; i < (len - message.length()) / 2; i++)
    std::cout << "*";
}

std::string trim(std::string str) {
  size_t firstOf;
  size_t firstNotOf;
  size_t lastOf;
  size_t lastNotOf;

  firstOf = str.find_first_of(' ');
  firstNotOf = str.find_first_not_of(' ');
  if (firstOf < firstNotOf)
    str.erase(firstOf, firstNotOf);

  lastOf = str.find_last_of(' ');
  lastNotOf = str.find_last_not_of(' ');
  if (lastOf > lastNotOf)
    str.erase(lastNotOf + 1, lastOf);

  return str;
}

int main() {
  winsize window;
  PhoneBook phoneBook;
  std::string input;

  ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
  printDecoration(window.ws_col, " Welcome to your PhoneBook ");
  std::cout << WHITE << std::endl << std::endl;

  while (1) {
    std::cout << "Enter your command : ";
    std::getline(std::cin, input);

    if (!strcmp(trim(input).c_str(), "ADD"))
      phoneBook.addContact();
    else if (!strcmp(trim(input).c_str(), "SEARCH"))
      phoneBook.searchContact();
    else if (strcmp(trim(input).c_str(), "EXIT") && !std::cin.eof())
      std::cout << RED << "command \"" << input << "\" not found\n";

    if (!strcmp(input.c_str(), "EXIT") || std::cin.eof()) {
      std::cout << (std::cin.eof() ? "\n" : "") << std::endl;
      printDecoration(window.ws_col, " Goodbye ");
      break;
    }

    std::cout << WHITE << std::endl;
  }

  return 0;
}
