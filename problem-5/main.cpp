#include <iostream>

template<int max>
bool divisibleByEach(const int n) {
    for (int i = 1; i <= max; i++) {
        if (n % i != 0) return false;
    }
    return true;
}

int main() {
    for (int i = 1; ; i++) {
        if (divisibleByEach<20>(i)) {
            std::cout << i << '\n';
            break;
        }
    }
    return 0;
}