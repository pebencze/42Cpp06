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

	void invalid(void) {
		std::cout << "char: invalid conversion" << std::endl;
		std::cout << "int: invalid conversion" << std::endl;
		std::cout << "float: invalid conversion" << std::endl;
		std::cout << "double: invalid conversion" << std::endl;
	}

	int	checkDigits(const std::string &literal) {
		int i = 0;
		int dotCount = 0;
		int fCount = 0;

		if (literal[i] == '-' || literal[i] == '+')
			i++;
		if (!isdigit(literal[i])) {
			invalid();
			return (1);
		}
		while (literal[++i]) {
			if (literal[i] == '.' && dotCount == 0) {
				dotCount++;
				continue ;
			}
			if (literal[i] == 'f' && fCount == 0) {
				fCount++;
				continue ;
			}
			if (!isdigit(literal[i])) {
				invalid();
				return (1);
			}
		}
		return (0);
	}

   void  printCases(char c, int i, float f, double d) {
      if (d > 127 || d < 0 || !isprint(i))
         std::cout << "char: non displayable" << std::endl;
      else
         std::cout << "char: " << c << std::endl;
      if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
         std::cout << "int: overflow" << std::endl;
      else
         std::cout << "int: " << i << std::endl;
      if (f == HUGE_VALF || f == -HUGE_VALF || f > std::numeric_limits<float>::max() || f < -(std::numeric_limits<float>::max()))
         std::cout << "float: overflow" << std::endl;
      else
         std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
      if (d == HUGE_VAL || d == -HUGE_VAL)
         std::cout << "double: overflow" << std::endl;
      else
         std::cout << "double: " << d << std::endl;
   }

	void convertToChar(char *c, int *i, float *f, double *d, std::string const &literal) {
		*c = static_cast<char>(literal[0]);
		*i = static_cast<int>(*c);
		*d = static_cast<double>(*c);
		*f = static_cast<float>(*c);
		printCases(*c, *i, *f, *d);
	}

	void convertToFloat(char *c, int *i, float *f, double *d, std::string const &literal) {
		*f = strtof(literal.c_str(), NULL);
		*d = static_cast<double>(*f);
		*c = static_cast<char>(*f);
		*i = static_cast<int>(*f);
		 printCases(*c, *i, *f, *d);
	}

	void convertToDouble(char *c, int *i, float *f, double *d, std::string const &literal) {
		*d = strtod(literal.c_str(), NULL);
		*f = static_cast<float>(*d);
		*c = static_cast<char>(*d);
		*i = static_cast<int>(*d);
		printCases(*c, *i, *f, *d);
	}

	void convertToInt(std::string const &literal) {
		long int temp = strtol(literal.c_str(), NULL, 10);
		if (temp > 127 || temp < 0 || !isprint(static_cast<int>(temp)))
			std::cout << "char: non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(temp) << std::endl;
		if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
			std::cout << "int: overflow" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(temp) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(temp) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(temp) << std::endl;
	}
}

void ScalarConverter::convert(std::string const &literal) {
	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;

	if (Utils::specialCases(literal))
		return ;
	if (literal.length() == 1 && !isdigit(literal[0]))
	{
		Utils::convertToChar(&c, &i, &f, &d, literal);
		Utils::printCases(c, i, f, d);
	}
	else {
		if (Utils::checkDigits(literal)) {
			return ;
		}
		if (literal.find("f") != std::string::npos && literal.find(".") != std::string::npos)
			Utils::convertToFloat(&c, &i, &f, &d, literal);
		else if (literal.find(".") != std::string::npos)
			Utils::convertToDouble(&c, &i, &f, &d, literal);
		else
			Utils::convertToInt(literal);
	}

}
