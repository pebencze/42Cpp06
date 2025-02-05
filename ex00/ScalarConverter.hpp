#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <iomanip>
# include <cmath>
# include <cerrno>

class ScalarConverter {
    public:
        static void convert(std::string const &literal);

    private:
        ScalarConverter(); //default constructor
        ScalarConverter(const std::string &); //parameterized constructor
        ScalarConverter(const ScalarConverter &); //copy constructor
        ~ScalarConverter(); //destructor

        ScalarConverter &operator=(const ScalarConverter &rhs); //operator overload

};
#endif
