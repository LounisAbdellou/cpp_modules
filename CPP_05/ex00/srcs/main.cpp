#include "Bureaucrat.hpp"
#include "iostream"

int main() {
  try {
    Bureaucrat bureaucrat(1, "Jack");
    std::cout << bureaucrat << std::endl;
    bureaucrat.promote();
  } catch (std::exception &exception) {
    std::cout << "Error: " << exception.what() << std::endl;
  }

  try {
    Bureaucrat bureaucrat(150, "David");
    std::cout << bureaucrat << std::endl;
    bureaucrat.demote();
  } catch (std::exception &exception) {
    std::cout << "Error: " << exception.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Bureaucrat bureaucrat(0, "Luke");
    std::cout << bureaucrat << std::endl;
  } catch (std::exception &exception) {
    std::cout << "Error: " << exception.what() << std::endl;
  }

  try {
    Bureaucrat bureaucrat(151, "Willis");
    std::cout << bureaucrat << std::endl;
  } catch (std::exception &exception) {
    std::cout << "Error: " << exception.what() << std::endl;
  }

  return 0;
}
