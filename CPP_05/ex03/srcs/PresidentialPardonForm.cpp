#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential pardon", 25, 5) {
  this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : AForm(src) {
  *this = src;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential pardon", 25, 5) {
  this->_target = target;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
  if (this == &src)
    return *this;

  this->_target = src.getTarget();
  this->setIsSigned(src.getIsSigned());

  return *this;
}

const std::string &PresidentialPardonForm::getTarget() const {
  return this->_target;
}

void PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat) {
  if (this->getIsSigned()) {
    std::cout << "Form (" << this->getName() << ") is already signed"
              << std::endl;
    return;
  }

  if (this->getGradeToSign() < bureaucrat.getGrade())
    throw AForm::GradeTooLowException();

  this->setIsSigned(true);
}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) {
  if (!this->getIsSigned()) {
    std::cout << "Form (" << this->getName() << ") is not signed" << std::endl;
    return;
  }

  if (this->getGradeToExecute() < bureaucrat.getGrade())
    throw AForm::GradeTooLowException();

  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}
