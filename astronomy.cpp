#include <bits/stdc++.h>

int main() {
	using namespace std;
	// read number of test cases
	int t;
	cin >> t;
	while (t--) {
		// read input
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (auto & x : a) cin >> x;
		for (auto & x : b) cin >> x;

		bool saved = 0;

		// try capturing the same rotations and checking if the discs are equal
		rotate(begin(a), find(begin(a), end(a), b[0]), end(a));
		saved = a == b;

		// try capturing the same rotations on the reverse (by flipping the disc) and checking if the discs are equal
		reverse(begin(a), end(a));
		rotate(begin(a), find(begin(a), end(a), b[0]), end(a));
		saved |= a == b;

		cout << (saved ? "Saved\n" : "Doomed\n");
	}
	return 0;
}
