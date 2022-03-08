#include <iostream>

using namespace std;

int main() {
    int elements;
    // Read in how many elements we need to help Superman identify
    cin >> elements;
    for(int i = 0; i < elements; i++){
        int a;
        // Read in the value of the element
        cin >> a;
        // Print the square of the element so that Superman can look it up on the periodic table
        cout << a * a << endl;
    }
    return 0;
}
