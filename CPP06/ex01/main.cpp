#include<iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(){
    Data data;
    data.value = 42;
    data.name = "Wolfsburg";

    std::cout << "Original Data address: " << &data << std::endl;

    // Serialize the pointer
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized (uintptr_t): " << raw << std::endl;

    // Deserialize back
    Data* recovered = Serializer::deserialize(raw);
    std::cout << "Recovered pointer:      " << recovered << std::endl;


    if (recovered == &data)
        std::cout << "Success: pointers match!" << std::endl;
    else
        std::cout << "Error: pointers DO NOT match!" << std::endl;

    // Extra check: data content is still intact
    std::cout << "Recovered->value = " << recovered->value << std::endl;
    std::cout << "Recovered->name  = " << recovered->name << std::endl;
 
    return 0;

}
