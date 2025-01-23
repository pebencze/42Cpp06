#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <unistd.h>
#include <iostream>

int main(void) {
    Base* array[5];
    A a;
    B b;
    C c;

    for (int i = 0; i < 5; i++) {
        array[i] = generate();
        usleep(500);
    }

    std::cout << std::endl;
    std::cout << "Identify pointers: " << std::endl;
    for (int i = 0; i < 5; i++) {
       identify(array[i]);
    }
    std::cout << std::endl;

    std::cout << "Identify references: " << std::endl;
    identify(&a);
    identify(&b);
    identify(&c);
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
       delete array[i];
    }
    return (0);
}