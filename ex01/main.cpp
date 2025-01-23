#include "Serializer.hpp"

int main(void) {
    Data data = {"hello", 42, 4.2f, 42.42};
    Data *dataPtr = new Data(data);
    Data *deserialized;
    uintptr_t raw;

    std::cout << std::endl << "Before serialization: " << std::endl;
    std::cout << "Address of dataPtr: " << dataPtr << std::endl;
    std::cout << dataPtr->s << ", " << dataPtr->i << ", " 
        << dataPtr->f << ", " << dataPtr->d << std::endl;

    raw = Serializer::serialize(dataPtr);
    std::cout << std::endl << "Uintptr: " << raw << std::endl;

    deserialized = Serializer::deserialize(raw);

    std::cout << std::endl << "After serialization: " << std::endl;
    std::cout << "Address of deserialized: " << deserialized << std::endl;
    std::cout << deserialized->s << ", " << deserialized->i << ", " 
        << deserialized->f << ", " << deserialized->d << std::endl << std::endl;

    delete dataPtr;

    return (0);
}