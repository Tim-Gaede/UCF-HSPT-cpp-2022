// array.cpp by Jacob Steinebronn
#include <iostream>
#include <vector>
using namespace std;

// This solution is needlessly complex. I decided to write the solution this way to show off
// a useful trick in c++, where you overload the in/out operators for vectors so your syntax
// can be much cleaner in main. It's a very nice thing when solving complex problems that
// helps your code be more elgant, easier to read, and most importantly, easier to debug!

istream& operator>>(istream &is, vector<int> &vec) {
    for(auto &x : vec) is >> x;
    return is;
}

ostream& operator<<(ostream &os, vector<int> &vec) {
    for(auto x : vec) os << x << " ";
    return os;
}

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        cin >> arr; 
        cout << arr << endl;
    }
}