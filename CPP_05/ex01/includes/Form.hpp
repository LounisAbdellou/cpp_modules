/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solid_42 </var/spool/mail/solid_42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:32:38 by solid_42          #+#    #+#             */
/*   Updated: 2024/11/23 23:32:47 by solid_42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
private:
  const std::string _name;
  const int _gradeToSign;
  const int _gradeToExecute;
  bool _isSigned;

public:
  Form();
  Form(const Form &src);
  Form(const std::string &name, int gradeToSign, int gradeToExecute);
  ~Form() {};

  Form &operator=(const Form &src);

  const std::string &getName() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  bool getIsSigned() const;

  void beSigned(const Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif // !FORM_HPP
