#include <iostream>
#include <array>
#include <cmath>

bool isPrime(const int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {

    int num = 0;
    for (int i = 2; ; i++) {
        if (isPrime(i)) {
            num++;
        }
        if (num >= 10001) {
            std::cout << i << '\n';
            break;
        }
    }

    return 0;
}