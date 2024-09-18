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