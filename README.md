# 42Cpp06
C++ casts.

## Static Cast
- Performs conversions known at compile time
- No runtime type checking (unlike dynamic_cast)
- More restrictive than reinterpret_cast
- More permissive than implicit conversion
- Cannot cast away const (use const_cast)
- Cannot convert between unrelated types <br>
Use when:<br>
- Converting numeric types
- Upcasting in inheritance hierarchy
- Converting void pointers
- You're sure about the types involved

## Const Cast
`const_cast` is used specifically to remove or add const qualification from variables. It's generally considered dangerous and should be used rarely:

## Reinterpret Cast
**Use with extreme caution and only when absolutely necessary!** <br>
`reinterpret_cast` is designed for:<br>
- Low Level Conversion <br>
- *Pointer-to-integer* and *integer-to-pointer* conversions <br>
- Type punning (reinterpreting the bit pattern of one type as another) <br>
<details>
<summary> Low Level Conversion </summary>
- They operate at the bit/byte level <br>
- No data transformation occurs <br>
- The binary representation stays exactly the same <br>
- They can be potentially unsafe if misused <br>
- They are platform-dependent <br>
- They bypass the type system's safety checks <br>
</details>


While reinterpret_cast is *generally considered dangerous* because it can break type safety, this specific use case (converting between uintptr_t and pointers in ex01) is one of its legitimate uses. 
*uintptr_t is specifically designed to be able to hold and restore pointer values*.
This is *commonly used in serialization* scenarios where you need to:
Convert a pointer to an integer value (for storage or transmission)
Later convert that integer value back to the original pointer type

## Dynamic Cast
Only works on polymorphic classes. <br>
Different implementations for pointers and references: <br>
pointers can be nullptr, so returning nullptr on failure makes sense. References must always refer to an object, so throwing an exception is more appropriate since references can't be "null".<br>

```cpp
void identify(Base* p) {
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    ...
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch (const std::bad_cast&) {}
    ...
}
```

## To Repeat
1. Because static member functions are not associated with a particular object, they can be called directly by using the class name and the scope resolution operator (e.g. Something::getValue()). Like static member variables, they can also be called through objects of the class type, though this is not recommended.<br><br>
2. virtual destructors
```cpp
class Base {
    public:
        ~Base() { }  // Non-virtual destructor
};

class Derived : public Base {
    private:
        int* ptr;
    public:
        Derived() : ptr(new int(42)) { }
        ~Derived() { delete ptr; }  // Won't be called in some cases!
};

int main() {
    // Case 1 - SAFE: Direct Derived pointer
    Derived* d = new Derived();
    delete d;  // Calls Derived destructor, then Base destructor

    // Case 2 - UNSAFE: Base pointer to Derived
    Base* b = new Derived();
    delete b;  // Only calls Base destructor! Memory leak!
}
```

