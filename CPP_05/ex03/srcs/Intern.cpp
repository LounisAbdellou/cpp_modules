#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "cstring"

Intern::Intern() {
  this->_forms[0].key = "Presidential pardon";
  this->_forms[0].func = &Intern::createPresidentialPardon;
  this->_forms[1].key = "Robotomy request";
  this->_forms[1].func = &Intern::createRobotomyRequest;
  this->_forms[2].key = "Shrubbery creation";
  this->_forms[2].func = &Intern::createShrubberyCreation;
}

Intern::Intern(const Intern &src) { *this = src; }

Intern &Intern::operator=(const Intern &src) {
  (void)src;
  return *this;
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) {
  AForm *form;

  for (size_t i = 0; i < 3; i++) {
    if (!std::strcmp(this->_forms[i].key.c_str(), formName.c_str())) {
      form = (this->*(this->_forms[i].func))(target);
      std::cout << "Intern creates " << *form << std::endl;
      return form;
    }
  }

  std::cout << "Intern could not create the form because it does not exist"
            << std::endl;
  return NULL;
}

AForm *Intern::createPresidentialPardon(const std::string &target) const {
  return new PresidentialPardonForm(target);
}

AForm *Intern::createShrubberyCreation(const std::string &target) const {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequest(const std::string &target) const {
  return new RobotomyRequestForm(target);
}
