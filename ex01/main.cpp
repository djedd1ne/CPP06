#include <iostream>
#include <stdint.h>
#include "Serializer.hpp"

int main(void){
    Data data;
    Data *recasted;
    uintptr_t raw;

    data.s = "This is a string";
    data.n = 10;
    std::cout << "Before serialize:" << std::endl;
    std::cout << "Adress: " << &data
    << "\nString: " << data.s
    << "\nInteger: " << data.n << std::endl;

    raw = serialize(&data);
    recasted = deserialize(raw);

    std::string line (30, '*');
    std::cout << line << std::endl;
    std::cout << "After serialize:" << std::endl;
    std::cout << "Adress: " << recasted
    << "\nString: " << recasted->s
    << "\nInteger: " << recasted->n << std::endl;

    return(0);
}