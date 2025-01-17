#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
   std::cout << "Default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const std::string &name) {
   std::cout << "Parameterized constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
   std::cout << "Copy constructor called." << std::endl;
}

ScalarConverter::~ScalarConverter() {
   std::cout << "Destructor called." << std::endl;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &rhs) {
   if (this != &rhs) {}
   return (*this);
}
