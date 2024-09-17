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
