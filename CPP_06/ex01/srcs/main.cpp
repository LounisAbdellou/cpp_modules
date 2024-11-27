#include "Serializer.hpp"
#include <iostream>

int main() {
  Data data;
  uintptr_t serializedAddress;

  data.value = 42;

  std::cout << "Original address: " << &data << std::endl << std::endl;

  serializedAddress = Serializer::serialize(&data);

  std::cout << "Serialized address: " << serializedAddress << std::endl;

  std::cout << "Deserialized address: "
            << Serializer::deserialize(serializedAddress) << std::endl;

  return 0;
}
