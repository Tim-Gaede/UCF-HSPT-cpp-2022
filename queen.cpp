// queen.cpp by Jacob Steinebronn
#include <bits/stdc++.h>
using namespace std;

void solveOneTest(){
    int n; cin >> n;
    int ans = (2*n+1)*(2*n+1); // The number of squares on the grid
    ans -= 8*n; // The number of squares the queen can attack
    ans -= 1; // The queen's square itself.
    cout << ans << "\n";
}

int main(){
    int numTests; cin >> numTests;
    while(numTests--) solveOneTest();
    return 0;
}
