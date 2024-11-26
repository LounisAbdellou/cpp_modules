#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("John Doe") { this->_grade = 150; }

Bureaucrat::Bureaucrat(int grade, const std::string &name) : _name(name) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();

  this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) { *this = src; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
  if (this == &src)
    return *this;

  this->_grade = src.getGrade();

  return *this;
}

int Bureaucrat::getGrade() const { return this->_grade; }

const std::string &Bureaucrat::getName() const { return this->_name; }

void Bureaucrat::promote() {
  if (this->_grade - 1 < 1)
    throw Bureaucrat::GradeTooHighException();

  this->_grade -= 1;
}

void Bureaucrat::demote() {
  if (this->_grade + 1 > 150)
    throw Bureaucrat::GradeTooLowException();

  this->_grade += 1;
}

void Bureaucrat::signForm(AForm &form) const {
  try {
    form.beSigned(*this);
    std::cout << *this << " signed " << form << std::endl;
  } catch (std::exception &exception) {
    std::cout << *this << " couldn’t sign " << form << " because "
              << exception.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm &form) const {
  try {
    form.execute(*this);
    std::cout << *this << " executed " << form << std::endl;
  } catch (std::exception &exception) {
    std::cout << *this << " couldn’t execute " << form << " because "
              << exception.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();

  return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "your grade must not exceed 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "your grade must not subceed 150";
}
