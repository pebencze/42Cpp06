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

namespace Utils {
   int specialCases(std::string const &literal) {
      if (literal == "+inf" || literal == "-inf"
         || literal == "+inff" ||  literal == "-inff"
         || literal == "nan" || literal == "nanf") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
         }
      if (!literal.compare("-inf") || !literal.compare("-inff")) {
         std::cout << "float: -inff" << std::endl;
         std::cout << "double: -inf" << std::endl;
         return (1);
      } else if (!literal.compare("+inf") || !literal.compare("+inff")) {
         std::cout << "float: +inff" << std::endl;
         std::cout << "double: +inf" << std::endl;
         return (1);
      } else if (!literal.compare("nan") || !literal.compare("nanf")) {
         std::cout << "float: nanf" << std::endl;
         std::cout << "double: nan" << std::endl;
         return (1);
      }
      return (0);
   }

   void  printCases(char c, int i, float f, double d) {
      if (!isprint(i))
         std::cout << "char: non displayable" << std::endl;
      else
         std::cout << "char: " << c << std::endl;
      if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
         std::cout << "int: overflow" << std::endl;
      else
         std::cout << "int: " << i << std::endl;
      if (f > std::numeric_limits<float>::max() || f < std::numeric_limits<float>::lowest())
         std::cout << "float: overflow" << std::endl;
      else
         std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
      if (d > std::numeric_limits<double>::max() || d < std::numeric_limits<double>::lowest())
         std::cout << "double: overflow" << std::endl;
      else
         std::cout << "double: " << d << std::endl;
   }

/*    void convertToFloat(char *c, int *i, float *f, double *d, std::string const &literal) {
         *f = atof(literal.c_str());
         *d = static_cast<double>(*f);
         *c = static_cast<char>(*f);
         *i = static_cast<int>(*f);
   } */
   void convertToDouble(char *c, int *i, float *f, double *d, std::string const &literal) {
         *d = strtod(literal.c_str(), NULL);
         *f = static_cast<float>(*d);
         *c = static_cast<char>(*d);
         *i = static_cast<int>(*d);
   }
/*    void convertToInt(char *c, int *i, float *f, double *d, std::string const &literal) {
         *i = atoi(literal.c_str());
         *d = static_cast<double>(*i);
         *c = static_cast<char>(*i);
         *f = static_cast<float>(*i);
   } */
}

void ScalarConverter::convert(std::string const &literal) {
   try {
      char c = 0;
      int i = 0;
      float f = 0.0f;
      double d = 0.0;

      if (Utils::specialCases(literal))
         return ;
      if (literal.length() == 1) {
         c = static_cast<char>(literal[0]);
         i = static_cast<int>(c);
         d = static_cast<double>(c);
         f = static_cast<float>(c);
         return (Utils::printCases(c, i, f, d));
/*       } else if (literal.find("f") != std::string::npos && literal.find(".") != std::string::npos) {
         try {
            Utils::convertToFloat(&c, &i, &f, &d, literal);
         } catch (std::exception &e) {
            Utils::convertToDouble(&c, &i, &f, &d, literal);
         }
      } else if (literal.find(".") != std::string::npos) {
         Utils::convertToDouble(&c, &i, &f, &d, literal); */
      } else {
         /* try {
            Utils::convertToInt(&c, &i, &f, &d, literal);
         } catch (std::exception &e) { */
         Utils::convertToDouble(&c, &i, &f, &d, literal);
      }
      Utils::printCases(c, i, f, d);
   } catch (std::invalid_argument &e) {
      std::cout << "char: invalid conversion" << std::endl;
      std::cout << "int: invalid conversion" << std::endl;
      std::cout << "float: invalid conversion" << std::endl;
      std::cout << "double: invalid conversion" << std::endl;
   } catch(std::out_of_range &e) {
      std::cout << "char: non displayable" << std::endl;
      std::cout << "int: overflow" << std::endl;
      std::cout << "float: overflow" << std::endl;
      std::cout << "double: overflow" << std::endl;
   }
}

