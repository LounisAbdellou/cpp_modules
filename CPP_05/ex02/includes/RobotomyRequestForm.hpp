#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class RobotomyRequestForm : public AForm {
private:
  std::string _target;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &src);
  RobotomyRequestForm(const std::string &target);
  virtual ~RobotomyRequestForm() {};

  RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

  const std::string &getTarget() const;

  void beSigned(const Bureaucrat &bureaucrat);
  void execute(const Bureaucrat &bureaucrat);
};

#endif // !ROBOTOMY_REQUEST_FORM_HPP
