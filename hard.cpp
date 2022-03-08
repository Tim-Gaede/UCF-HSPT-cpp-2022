#include <iostream>

void solve() {
    // Take input
    int l1, c1, l2, c2;
    std::cin >> l1 >> c1 >> l2 >> c2;

    // Since the difficulty is defined as l * c,
    // our answer is the max of this calculation over both problems
    std::cout << std::max(l1 * c1, l2 * c2) << "\n";
}

int main() {
    // Get case count and solve them
    int d; std::cin >> d;
    for (int test_case = 1; test_case <= d; ++test_case)
        solve();

    return 0;
}

