#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <iostream>

Base::~Base() {
}

/*It randomly instanciates A, B or C and returns the instance as a Base pointer.
Upcastimg -> no need of dynamic cast*/
Base * generate(void) {

    srand(time(NULL));
    int random = rand() % 3;

    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return (NULL);
}

/*It prints the actual type of the object pointed to by p: "A", "B" or "C".
Downcasting -> use of dynamic_cast*/
void identify(Base* p) {
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "NULL" << std::endl;
}
/*It prints the actual type of the object pointed to by p: "A", "B" or "C"
 Using a pointer inside this function is forbidden.
 Downcasting -> use of dynamic_cast.*/
void identify(Base& p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch (const std::exception&) {} //const prevents accidental modification of the object
    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch (const std::exception&) {}
    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return ;
    } catch (const std::exception&) {
        std::cout << "NULL" << std::endl;
    }
}
