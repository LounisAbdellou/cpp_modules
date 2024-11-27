#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

typedef struct {
  int value;
} Data;

class Serializer {
public:
  Serializer() {};
  Serializer(const Serializer &src);
  ~Serializer() {};

  Serializer &operator=(const Serializer &src);

  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif // !SERIALIZER_HPP
