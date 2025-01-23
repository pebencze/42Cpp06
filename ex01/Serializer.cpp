#include "Serializer.hpp"

Serializer::Serializer() {
   std::cout << "Default constructor called." << std::endl;
}

Serializer::Serializer(const std::string &name) {
   std::cout << "Parameterized constructor called." << std::endl;
}

Serializer::Serializer(const Serializer &src) {
   std::cout << "Copy constructor called." << std::endl;
}

Serializer::~Serializer() {
   std::cout << "Destructor called." << std::endl;
}

Serializer & Serializer::operator=(const Serializer &rhs) {
   if (this != &rhs) {}
   return (*this);
}
