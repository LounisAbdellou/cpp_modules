#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <string>

#define TREE                                                                   \
  "                                  # #### ####\n\
                                ### \\/#|### |/####\n\
                               ##\\/#/ \\||/##/_/##/_#\n\
                             ###  \\/###|/ \\/ # ###\n\
                           ##_\\_#\\_\\## | #/###_/_####\n\
                          ## #### # \\ #| /  #### ##/##\n\
                           __#_--###`  |{,###---###-~\n\
                                     \\ }{\n\
                                      }}{\n\
                                      }}{\n\
                                 ejm  {{}\n\
                                , -=-~{ .-^- _\n\
                                      `}\n\
                                       {\n"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
private:
  std::string _target;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &src);
  ShrubberyCreationForm(const std::string &target);
  virtual ~ShrubberyCreationForm() {};

  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

  const std::string &getTarget() const;

  void beSigned(const Bureaucrat &bureaucrat);
  void execute(const Bureaucrat &bureaucrat);
};

#endif // !SHRUBBERY_CREATION_FORM_HPP
