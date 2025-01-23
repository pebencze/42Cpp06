# 42Cpp06
C++ casts.

## To Repeat
1. Because static member functions are not associated with a particular object, they can be called directly by using the class name and the scope resolution operator (e.g. Something::getValue()). Like static member variables, they can also be called through objects of the class type, though this is not recommended.

## Reinterpret Cast
reinterpret_cast is designed for:
<details>
<summary>- Low Level Conversion</summary>
- They operate at the bit/byte level
- No data transformation occurs
- The binary representation stays exactly the same
- They can be potentially unsafe if misused
- They are platform-dependent
- They bypass the type system's safety checks
</details>
- *Pointer-to-integer* and *integer-to-pointer* conversions
- Type punning (reinterpreting the bit pattern of one type as another)

While reinterpret_cast is *generally considered dangerous* because it can break type safety, this specific use case (converting between uintptr_t and pointers in ex01) is one of its legitimate uses. 
*uintptr_t is specifically designed to be able to hold and restore pointer values*.
This is *commonly used in serialization* scenarios where you need to:
Convert a pointer to an integer value (for storage or transmission)
Later convert that integer value back to the original pointer type

