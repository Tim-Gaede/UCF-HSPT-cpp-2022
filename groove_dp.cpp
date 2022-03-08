#include <bits/stdc++.h>

using namespace std;

/*

The simplest way to solve this problem is with 2-pointer sweep (see java or python solution)

This problem can also be solved using Dynamic Programming (DP). If you are unfamiliar with DP, it is very interesting and
useful to know. You can easily find many sources online that teach DP.

This problem can also be solved with binary search (see other c++ solution).

Solution:
We cannot simply iterate over all sequences as that would be O(n^2) which is too slow for n=10^5.

A certain value a[i] can be part of many flow sequences, but it only makes sense to store the greatest flow value it can 
be a part of, so to solve this problem with DP, we can simply store the greatest flow that a certain value can be a part of.
To have a flow value of x, you must have all of the values going up from 1 to x, followed by all of the values going down 
from x to 1, so we can store for each value whether you have gone up to it, and the maximum flow value that goes down to it.
The answer will be the maximum flow that goes down all the way back to 1.


*/

int main(){

    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int maxv = 100001;
        //up[i] stores whether we can go up to i
        vector<bool> up(maxv);
        //down[i] stores the greatest sequence that goes up and comes back down to i
        vector<int> down(maxv);
        for(int i=0;i<n;i++){
            //if you can already go up to the current value, you can start going down
            if(up[a[i]]){
                down[a[i]] = a[i];
            }
            //if you can continue going down from a greater sequence, store that greater sequence
            if(down[a[i] + 1] != 0){
                down[a[i]] = down[a[i] + 1];
            }

            //you can go up to the current value if you have already seen every value before it (or if the current value is 1)
            if(a[i] == 1 || up[a[i] - 1]){
                up[a[i]] = true;
            }

        }
        //the answer is the greatest sequence that goes all the way down to 1
        cout<<down[1]<<endl;

    }

}

