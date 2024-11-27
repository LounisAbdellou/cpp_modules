#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
  srand((unsigned int)time(NULL));
  int randomNumber = (rand() % 3) + 1;

  if (randomNumber == 1)
    return new A();
  else if (randomNumber == 2)
    return new B();

  return new C();
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "REF: type A" << std::endl;
  } catch (std::exception &e) {
  }
  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "REF: type B" << std::endl;
  } catch (std::exception &e) {
  }
  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "REF: type C" << std::endl;
  } catch (std::exception &e) {
  }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "PTR: type A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "PTR: type B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "PTR: type C" << std::endl;
}

int main() {
  Base *ptr = generate();

  identify(ptr);
  identify(*ptr);

  delete ptr;

  return 0;
}
