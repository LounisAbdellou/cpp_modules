#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
public:
  int currentIndex;
  std::string ideas[100];

  Brain();
  Brain(const Brain &src);
  ~Brain();

  Brain &operator=(const Brain &src);

  void addIdeas(const std::string &newIdeas);
  void displayIdeas() const;
};

#endif // !BRAIN_HPP
