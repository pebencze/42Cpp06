#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

class Serializer {
    public:
        Serializer(); //default constructor
        Serializer(const std::string &name); //parameterized constructor
        Serializer(const Serializer &src); //copy constructor
        ~Serializer(); //destructor

        Serializer &operator=(const Serializer &rhs); //operator overload

};
#endif
