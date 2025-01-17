#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter {
    public:
        ScalarConverter(); //default constructor
        ScalarConverter(const std::string &name); //parameterized constructor
        ScalarConverter(const ScalarConverter &src); //copy constructor
        ~ScalarConverter(); //destructor

        ScalarConverter &operator=(const ScalarConverter &rhs); //operator overload

};
#endif
