#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _gradeToSign(150), _gradeToExecute(150) {
  this->_isSigned = 0;
}

Form::Form(const Form &src)
    : _name(src.getName()), _gradeToSign(src.getGradeToSign()),
      _gradeToExecute(src.getGradeToExecute()) {
  *this = src;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute > 150)
    throw Form::GradeTooHighException();
  else if (gradeToSign > 150 || gradeToExecute > 150)
    throw Form::GradeTooLowException();
  this->_isSigned = 0;
}

Form &Form::operator=(const Form &src) {
  if (this == &src)
    return *this;

  this->_isSigned = src.getIsSigned();

  return *this;
}

const std::string &Form::getName() const { return this->_name; }

int Form::getGradeToSign() const { return this->_gradeToSign; }

int Form::getGradeToExecute() const { return this->_gradeToExecute; }

bool Form::getIsSigned() const { return this->_isSigned; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (this->_isSigned) {
    std::cout << "Form (" << this->_name << ") is already signed";
    return;
  }

  if (this->_gradeToSign < bureaucrat.getGrade())
    throw Form::GradeTooLowException();
  else
    this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "grade is to high";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "grade is to low";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
  out << form.getName() << " form (";
  out << (form.getIsSigned() ? "is signed, " : "is not signed, ");
  out << "grade " << form.getGradeToSign() << " is needed to sign, ";
  out << "grade " << form.getGradeToExecute() << " is needed to execute)";

  return out;
}
