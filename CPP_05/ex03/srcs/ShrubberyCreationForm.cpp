#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Presidential pardon", 145, 137) {
  this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src) {
  *this = src;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Presidential pardon", 145, 137) {
  this->_target = target;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
  if (this == &src)
    return *this;

  this->_target = src.getTarget();
  this->setIsSigned(src.getIsSigned());

  return *this;
}

const std::string &ShrubberyCreationForm::getTarget() const {
  return this->_target;
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &bureaucrat) {
  if (this->getIsSigned()) {
    std::cout << "Form (" << this->getName() << ") is already signed"
              << std::endl;
    return;
  }

  if (this->getGradeToSign() < bureaucrat.getGrade())
    throw AForm::GradeTooLowException();

  this->setIsSigned(true);
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) {
  if (!this->getIsSigned()) {
    std::cout << "Form (" << this->getName() << ") is not signed" << std::endl;
    return;
  }

  if (this->getGradeToExecute() < bureaucrat.getGrade())
    throw AForm::GradeTooLowException();

  std::ofstream outfile;
  std::string filename = this->_target + "_shrubbery";

  outfile.open(filename.c_str());
  if (!outfile.is_open()) {
    std::cout << "Something went wrong while opening outfile" << std::endl;
    return;
  }

  outfile << TREE;
}
