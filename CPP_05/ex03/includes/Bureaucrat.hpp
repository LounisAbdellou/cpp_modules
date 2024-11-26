#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class AForm;

class Bureaucrat {
private:
  int _grade;
  const std::string _name;

public:
  Bureaucrat();
  Bureaucrat(int grade, const std::string &name);
  Bureaucrat(const Bureaucrat &src);
  ~Bureaucrat() {};

  Bureaucrat &operator=(const Bureaucrat &src);

  int getGrade() const;
  const std::string &getName() const;

  void promote();
  void demote();
  void signForm(AForm &form) const;
  void executeForm(AForm &form) const;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif // !BUREAUCRAT_HPP
