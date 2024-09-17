#include <iostream>
#include <iomanip>
#include <bitset>
#include <cstring> 

void printIEEE754(float number) {
    
    union {
        float f;
        uint32_t bits;
    } value;

    value.f = number;

    // Print  bit 1 bit
    std::cout << "Sign bit: " << ((value.bits >> 31) & 1) << std::endl;

    // Print the 8 bits
    std::cout << "Exponent: " << std::bitset<8>((value.bits >> 23) & 0xFF) << std::endl;

    // Print the 23 bits
    std::cout << "Mantissa: " << std::bitset<23>(value.bits & 0x7FFFFF) << std::endl;

    // Print the 32-bit binary
    std::cout << "IEEE 754 encoding: " << std::bitset<32>(value.bits) << std::endl;

    // Print the hexadecimal
    std::cout << "Hexadecimal: 0x" << std::hex << value.bits << std::endl;
}

int main() {
    float num1 = 56.8;
    float num2 = -56.8;

    std::cout << "Encoding of 56.8:" << std::endl;
    printIEEE754(num1);

    std::cout << std::endl;

    std::cout << "Encoding of -56.8:" << std::endl;
    printIEEE754(num2);

    return 0;
}
