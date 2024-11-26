#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "iostream"

int main() {
  try {
    // PresidentialPardonForm form("David");
    // RobotomyRequestForm form("David");
    ShrubberyCreationForm form("David");
    Bureaucrat bureaucrat(1, "Jack");

    bureaucrat.signForm(form);
    bureaucrat.executeForm(form);
  } catch (std::exception &exception) {
    std::cout << "Error: " << exception.what() << std::endl;
  }

  return 0;
}
