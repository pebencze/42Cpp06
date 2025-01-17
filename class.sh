#!/bin/bash

NAME=$1
UPPERCASE_NAME=$(echo "$NAME" | tr '[:lower:]' '[:upper:]') #${NAME^^}
DIRECTORY=$2

mkdir -p $DIRECTORY
cd $DIRECTORY
touch "$NAME.cpp"
touch "$NAME.hpp"

echo "#ifndef "$UPPERCASE_NAME"_HPP" > $NAME.hpp
echo "# define "$UPPERCASE_NAME"_HPP" >> $NAME.hpp
echo "" >> $NAME.hpp
echo "# include <iostream>" >> $NAME.hpp
echo "" >> $NAME.hpp

echo "class $NAME {" >> $NAME.hpp
echo "    public:" >> $NAME.hpp
echo "        $NAME(); //default constructor" >> $NAME.hpp
echo "        $NAME(const std::string &name); //parameterized constructor" >> $NAME.hpp
echo "        $NAME(const $NAME &src); //copy constructor" >> $NAME.hpp
echo "        ~$NAME(); //destructor" >> $NAME.hpp
echo "" >> $NAME.hpp
echo "        $NAME &operator=(const $NAME &rhs); //operator overload" >> $NAME.hpp
echo "" >> $NAME.hpp
#echo "    private:" >> $NAME.hpp
echo "};" >> $NAME.hpp

echo "#endif" >> $NAME.hpp

echo "#include \"$NAME.hpp\"" > $NAME.cpp
echo "" >> $NAME.cpp
echo "$NAME::$NAME() {" >> $NAME.cpp
echo "   std::cout << \"Default constructor called.\" << std::endl;" >> $NAME.cpp
echo "}" >> $NAME.cpp
echo "" >> $NAME.cpp
echo "$NAME::$NAME(const std::string &name) {" >> $NAME.cpp
echo "   std::cout << \"Parameterized constructor called.\" << std::endl;" >> $NAME.cpp
echo "}" >> $NAME.cpp
echo "" >> $NAME.cpp
echo "$NAME::$NAME(const $NAME &src) {" >> $NAME.cpp
echo "   std::cout << \"Copy constructor called.\" << std::endl;" >> $NAME.cpp
echo "}" >> $NAME.cpp
echo "" >> $NAME.cpp
echo "$NAME::~$NAME() {" >> $NAME.cpp
echo "   std::cout << \"Destructor called.\" << std::endl;" >> $NAME.cpp
echo "}" >> $NAME.cpp
echo "" >> $NAME.cpp
echo "$NAME & $NAME::operator=(const $NAME &rhs) {" >> $NAME.cpp
echo "   if (this != &rhs) {}" >> $NAME.cpp
echo "   return (*this);" >> $NAME.cpp
echo "}" >> $NAME.cpp

cd ..
echo "Created $NAME.cpp and $NAME.hpp with a shell script"


