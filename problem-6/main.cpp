#include <iostream>

int main() {
    const int MAX = 100;
    uint64_t squareOfSum = 0;
    uint64_t sumOfSquares = 0;
    for (int i = 1; i <= 100; i++) {
        squareOfSum += i;
        sumOfSquares += i * i;
    }
    squareOfSum *= squareOfSum;

    std::cout << squareOfSum - sumOfSquares << std::endl;
    return 0;
}