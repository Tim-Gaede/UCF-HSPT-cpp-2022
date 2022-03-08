#include <iostream>

using namespace std;

int main() {
    int missions;
    // Read in the number of missions
    cin >> missions;
    for(int i = 0; i < missions; i++){
        int a, b;
        // Read in number of sticks, number of pillars, respectively.
        cin >> a >> b;
        if (b == 0){
            // If there are no pillars, print "this is madness"
            // Very important check to ensure no divide by 0 errors occur.
            printf("this is madness\n");
        }else{
            printf("%.3f\n",(1.0 * a / b));
        }
        
    }
    return 0;
}
