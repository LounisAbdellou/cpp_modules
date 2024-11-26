/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solid_42 </var/spool/mail/solid_42>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:32:38 by solid_42          #+#    #+#             */
/*   Updated: 2024/11/26 17:13:07 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
  const std::string _name;
  const int _gradeToSign;
  const int _gradeToExecute;
  bool _isSigned;

public:
  AForm();
  AForm(const AForm &src);
  AForm(const std::string &name, int gradeToSign, int gradeToExecute);
  virtual ~AForm() {};

  AForm &operator=(const AForm &src);

  const std::string &getName() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  bool getIsSigned() const;

  void setIsSigned(bool isSigned);

  virtual void beSigned(const Bureaucrat &bureaucrat) = 0;
  virtual void execute(const Bureaucrat &bureaucrat) = 0;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif // !AFORM_HPP
