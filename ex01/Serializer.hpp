#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer {
    public:
        ~Serializer(); //destructor

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

    private:
        Serializer(); //default constructor
        Serializer(const std::string &); //parameterized constructor
        Serializer(const Serializer &); //copy constructor
        Serializer &operator=(const Serializer &rhs); //operator overload
};
#endif
