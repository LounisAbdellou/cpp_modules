#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "iostream"

int main() {
  try {
    Bureaucrat bureaucrat(2, "Jack");
    Form formOne("B12", 1, 1);
    Form formTwo("B14", 3, 3);

    bureaucrat.signForm(formOne);
    std::cout << std::endl;
    bureaucrat.signForm(formTwo);
  } catch (std::exception &exception) {
    std::cout << "Error: " << exception.what() << std::endl;
  }

  return 0;
}
