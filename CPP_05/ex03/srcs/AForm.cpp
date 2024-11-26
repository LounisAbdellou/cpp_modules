#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _gradeToSign(150), _gradeToExecute(150) {
  this->_isSigned = false;
}

AForm::AForm(const AForm &src)
    : _name(src.getName()), _gradeToSign(src.getGradeToSign()),
      _gradeToExecute(src.getGradeToExecute()) {
  *this = src;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute > 150)
    throw AForm::GradeTooHighException();
  else if (gradeToSign > 150 || gradeToExecute > 150)
    throw AForm::GradeTooLowException();
  this->_isSigned = false;
}

AForm &AForm::operator=(const AForm &src) {
  if (this == &src)
    return *this;

  this->_isSigned = src.getIsSigned();

  return *this;
}

const std::string &AForm::getName() const { return this->_name; }

int AForm::getGradeToSign() const { return this->_gradeToSign; }

int AForm::getGradeToExecute() const { return this->_gradeToExecute; }

bool AForm::getIsSigned() const { return this->_isSigned; }

void AForm::setIsSigned(bool isSigned) { this->_isSigned = isSigned; }

const char *AForm::GradeTooHighException::what() const throw() {
  return "grade is to high";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "grade is to low";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
  out << form.getName() << " form (";
  out << (form.getIsSigned() ? "is signed, " : "is not signed, ");
  out << "grade " << form.getGradeToSign() << " is needed to sign, ";
  out << "grade " << form.getGradeToExecute() << " is needed to execute)";

  return out;
}
