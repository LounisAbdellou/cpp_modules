#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "iostream"

int main() {
  Intern *intern = new Intern();
  AForm *form = intern->makeForm("Presidential pardon", "David");

  try {
    Bureaucrat bureaucrat(1, "Jack");

    if (form) {
      bureaucrat.signForm(*form);
      bureaucrat.executeForm(*form);
    }
  } catch (std::exception &exception) {
    std::cout << "Error: " << exception.what() << std::endl;
  }

  delete intern;
  delete form;

  return 0;
}
