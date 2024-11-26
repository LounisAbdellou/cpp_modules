#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
  typedef struct s_forms {
    std::string key;
    AForm *(Intern::*func)(const std::string &) const;
  } t_forms;

private:
  t_forms _forms[3];
  AForm *createPresidentialPardon(const std::string &target) const;
  AForm *createShrubberyCreation(const std::string &target) const;
  AForm *createRobotomyRequest(const std::string &target) const;

public:
  Intern();
  Intern(const Intern &src);
  ~Intern() {};

  Intern &operator=(const Intern &src);

  AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif // !INTERN_HPP
