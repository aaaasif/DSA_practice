#include <iostream>

int main() {
    int i, j;
    float a[10000];

    // Initialize the array with a value of 1.0
    for (i = 0; i < 10000; i++) {
        a[i] = 1.0;
    }

    // Nested loop to perform some operation (fixed syntax)
    for (i = 0; i < 10000; i++) { // Outer loop
        for (j = 1; j < 10000; j++) { // Inner loop
            a[i] = a[j]; // Operation (note: it overwrites `a[i]` repeatedly)
        }
    }

    // Output the first 10 values to verify
    for (i = 0; i < 10; i++) {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    return 0;
}
