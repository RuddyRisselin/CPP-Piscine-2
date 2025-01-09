#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.value = 42;
    data.text = "Hello, Serialization!";

    std::cout << "Original Data: " << std::endl;
    std::cout << "  value: " << data.value << std::endl;
    std::cout << "  text: " << data.text << std::endl;

    unsigned long raw = Serializer::serialize(&data);

    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "\nDeserialized Data: " << std::endl;
    std::cout << "  value: " << deserializedData->value << std::endl;
    std::cout << "  text: " << deserializedData->text << std::endl;

    if (&data == deserializedData)
        std::cout << "\nIntegrity check: PASSED (pointers match)" << std::endl;
	else
        std::cout << "\nIntegrity check: FAILED (pointers do not match)" << std::endl;

    return 0;
}
