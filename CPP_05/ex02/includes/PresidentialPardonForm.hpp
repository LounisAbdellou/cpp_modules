#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm {
private:
  std::string _target;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &src);
  PresidentialPardonForm(const std::string &target);
  virtual ~PresidentialPardonForm() {};

  PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

  const std::string &getTarget() const;

  void beSigned(const Bureaucrat &bureaucrat);
  void execute(const Bureaucrat &bureaucrat);
};

#endif // !PRESIDENTIAL_PARDON_FORM_HPP
