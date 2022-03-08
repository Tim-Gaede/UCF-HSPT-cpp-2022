#include <iostream>

int main() {
	int y;
	std::cin >> y;
	while (y--) {
		int n, m;
		std::cin >> n >> m;
		// imagine an infinite sequence of integers [1, n]
		// we intend to jump to the mth position in the sequence of infinite length
		// jumping multiples of n is effectively the same problem, so we can remove all multiples of n from m
		// m exists in the range [0, n - 1], and person m was the last person to hold the door
		// so the (m + 1)th person is at the front of the line, where m + 1 is in the range [1, n] which is the range of all valid answers
		std::cout << (m % n) + 1 << '\n';
	}
	return 0;
}
