#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy request form", 72, 45) {
  this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src) {
  *this = src;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy request form", 72, 45) {
  this->_target = target;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
  if (this == &src)
    return *this;

  this->_target = src.getTarget();
  this->setIsSigned(src.getIsSigned());

  return *this;
}

const std::string &RobotomyRequestForm::getTarget() const {
  return this->_target;
}

void RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat) {
  if (this->getIsSigned()) {
    std::cout << "Form (" << this->getName() << ") is already signed"
              << std::endl;
    return;
  }

  if (this->getGradeToSign() < bureaucrat.getGrade())
    throw AForm::GradeTooLowException();

  this->setIsSigned(true);
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) {
  if (!this->getIsSigned()) {
    std::cout << "Form (" << this->getName() << ") is not signed" << std::endl;
    return;
  }

  if (this->getGradeToExecute() < bureaucrat.getGrade())
    throw AForm::GradeTooLowException();

  srand((unsigned int)time(NULL));

  if (rand() % 2)
    std::cout << "Bzrrzzrrzz... " << this->_target
              << " as been successfully robotomized" << std::endl;
  else
    std::cout << "Robotomy has failed" << std::endl;
}
