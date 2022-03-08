// odds.cpp by Jacob Steinebronn
#include <bits/stdc++.h>
using namespace std;

void solveOneTest() {
    string a, b; cin >> a >> b;
    int i = 0, j = b.size();
    // i is the first index from the start where the strings differ
    while(i < b.size() && a[i] == b[i]) i++;
    // j is the first index from the end where the strings differ
    while(j > 0 && a[j] == b[j-1]) j--;

    // If the distance between i and j is more than 1, there's no way to win
    if(i+1 < j) {
        cout << "0/1\n";
        return;
    }

    // the number of allowable letters is the distance between the end of the 
    // lcp (longest common prefix) and the lcs (longest common suffix).
    int num = i-j+1;
    int den = a.size();
    int div = gcd(num, den);
    // divide the numerator and denominator by the gcd to reduce the fraction
    cout << (num/div) << "/" << (den/div) << endl;
}

int main(){
    int numTests; cin >> numTests;
    while(numTests--) solveOneTest();
    return 0;
}
