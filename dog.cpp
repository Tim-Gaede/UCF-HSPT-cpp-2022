// dog.cpp by Jacob Steinebronn
#include <bits/stdc++.h>
using namespace std;

void solveOneTest(){
    int n, l, startX, startY, ans = 0;
    cin >> n >> l >> startX >> startY;
    while(n--){
        int x, y; cin >> x >> y;
        int dx = x - startX, dy = y - startY;

        // We can check if sqrt(x^2 + y^2) <= l by squaring both sides
        // of the equation. This way, we don't have to deal with 
        // floating-point numbers, which are annoying and imprecise.
        if(dx*dx + dy*dy <= l*l) ans++;
    }
    cout << ans << "\n";
}

int main(){
    int numTests; cin >> numTests;
    while(numTests--) solveOneTest();
    return 0;
}
