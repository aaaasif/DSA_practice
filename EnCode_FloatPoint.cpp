#include <iostream>
#include <iomanip>
#include <bitset>
#include <cstring>  // For memcpy

// Function to print the IEEE 754 encoding of a float
void printIEEE754(float number) {
    // Create a union to access the bits of the float
    union {
        float f;
        uint32_t bits;
    } value;

    value.f = number;

    // Print the sign bit (1 bit)
    std::cout << "Sign bit: " << ((value.bits >> 31) & 1) << std::endl;

    // Print the exponent (8 bits)
    std::cout << "Exponent: " << std::bitset<8>((value.bits >> 23) & 0xFF) << std::endl;

    // Print the mantissa (23 bits)
    std::cout << "Mantissa: " << std::bitset<23>(value.bits & 0x7FFFFF) << std::endl;

    // Print the full 32-bit binary representation
    std::cout << "IEEE 754 encoding: " << std::bitset<32>(value.bits) << std::endl;

    // Print the hexadecimal representation
    std::cout << "Hexadecimal: 0x" << std::hex << value.bits << std::endl;
}

int main() {
   
}
