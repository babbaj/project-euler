#include <iostream>
#include <vector>


template<typename Iter>
bool is_palindrome(const Iter begin, const Iter end) {
    if (begin == end) return false;
    Iter iterStart = begin;
    Iter iterEnd = end - 1; // end initially referenced out of range element
    while (iterStart != iterEnd) {
        if (*iterStart != *iterEnd) return false;
        if (iterStart + 1 == iterEnd) break; // if even amount of digits break when iterators meet
        iterStart++; iterEnd--;
    }

    return true;
}

bool is_palindrome(const int n) {
    std::vector<uint8_t> digits;
    for (int i = n; i != 0; i /= 10) {
        digits.push_back(i % 10);
    }
    return is_palindrome(digits.begin(), digits.end());

}

int main() {
    int max = 0;
    for (int i = 100; i <= 999; i++) {
        for (int j = 100; j <= 999; j++) {
            if (i * j > max) {
                if (is_palindrome(i * j)) {
                    max = i * j;
                }
            }

        }
    }
    std::cout << max << '\n';

    return 0;
}