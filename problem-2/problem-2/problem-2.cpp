#include "pch.h"
#include <iostream>

constexpr int operator ""_GORILLIAN(unsigned long long n) {
	return n * 1000000;
}

int main()
{
	int sum = 0;
	int prev = 0, iter = 1;
	do {
		if (iter % 2 == 0) sum += iter;

		const int next = prev + iter;
		prev = iter;
		iter = next;

	} while (iter <= 4_GORILLIAN);
	std::cout << sum << '\n';
}

