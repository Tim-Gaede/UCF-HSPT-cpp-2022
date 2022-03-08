// Catching Those Zs!
// Solution by Andy Phan

#include <bits/stdc++.h>

using namespace std;

int main() {
    // get number of lines in input
    string numLines;
    getline(cin, numLines);
    int n = stoi(numLines);

    // iterate over cases
    for (int caseNum = 0; caseNum < n; caseNum++) {
        // get line
        string s;
        getline(cin, s);

        // for-each loop over s to count number of z's
        int numZ = 0;
        for (char c : s) {
            if (c == 'z' || c == 'Z') {
                numZ++;
            }
        }

        // print output
        if (numZ >= 3) {
            cout << "Time to take a nap.\n";
        }
        else {
            cout << "Perry saves the day!\n";
        }
    }

    return 0;
}