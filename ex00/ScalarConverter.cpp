#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
   std::cout << "Default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const std::string &) {
   std::cout << "Parameterized constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &) {
   std::cout << "Copy constructor called." << std::endl;
}

ScalarConverter::~ScalarConverter() {
   std::cout << "Destructor called." << std::endl;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &rhs) {
   if (this != &rhs) {}
   return (*this);
}

void ScalarConverter::convert(std::string const &literal) {

   try {
      char c;
      int i;
      float f;
      double d;
      if (!literal.compare("-inf") || !literal.compare("-inff")) {
         std::cout << "char: impossible" << std::endl;
         std::cout << "int: impossible" << std::endl;
         std::cout << "float: -inff" << std::endl;
         std::cout << "double: -inf" << std::endl;
         return ;
      } else if (!literal.compare("+inf") || !literal.compare("+inff")) {
         std::cout << "char: impossible" << std::endl;
         std::cout << "int: impossible" << std::endl;
         std::cout << "float: +inff" << std::endl;
         std::cout << "double: +inf" << std::endl;
         return ;
      } else if (!literal.compare("nan") || !literal.compare("nanf")) {
         std::cout << "char: impossible" << std::endl;
         std::cout << "int: impossible" << std::endl;
         std::cout << "float: nanf" << std::endl;
         std::cout << "double: nan" << std::endl;
         return ;
      } else if (literal.length() == 1 && !isdigit(literal[0])) {
         c = static_cast<char>(literal[0]);
         //c = reinterpret_cast<char>(literal[0]);
         i = static_cast<int>(c);
         d = static_cast<double>(c);
         f = static_cast<float>(c);
      }
      
      
       else if (literal.find("f") != std::string::npos && literal.find(".") != std::string::npos) {
         f = std::stof(literal);
         d = static_cast<double>(f);
         c = static_cast<char>(f);
         i = static_cast<int>(f);
      } else if (literal.find(".") != std::string::npos) {
         d = std::stod(literal);
         f = static_cast<float>(d);
         c = static_cast<char>(d);
         i = static_cast<int>(d);
      } else {
         i = std::stoi(literal);
         f = static_cast<float>(i);
         c = static_cast<char>(i);
         d = static_cast<double>(i);
      }
      if (!isprint(i))
         std::cout << "char: non displayable" << std::endl;
      else
         std::cout << "char: " << c << std::endl;
         std::cout << "int: " << i << std::endl;
         std::cout << "float: " << f << "f" << std::endl;
         std::cout << "double: " << d << std::endl;
   }
   catch(std::exception &e) {
      std::cout << "char: non displayable" << std::endl;
      std::cout << "int: overflow" << std::endl;
      std::cout << "float: overflow" << std::endl;
      std::cout << "double: overflow" << std::endl;
      std::cout << e.what();
   }
}

