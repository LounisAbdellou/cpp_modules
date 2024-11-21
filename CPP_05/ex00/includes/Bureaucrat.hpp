#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
private:
  int _grade;
  const std::string _name;

public:
  Bureaucrat();
  Bureaucrat(int grade, const std::string &name);
  ~Bureaucrat() {};

  int getGrade() const;
  const std::string &getName() const;

  void promote();
  void demote();

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
