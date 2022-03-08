#include <bits/stdc++.h>

using namespace std;

/*

The simplest way to solve this problem is with 2-pointer sweep (see java or python solution)

This problem can also be solved using Binary Search. Binary Search is probably one of the most fundamental and useful algorithms
to know. You can find plenty of resources online to learn binary search.

This problem can also be solved with Dynamic Programming (see other c++ solution).

Solution:
We cannot simply iterate over all sequences as that would be O(n^2) which is too slow for n=10^5.

However, if a sequence has a flow value of x, then it must also have all flow values less than x. We can test whether a certain flow
value works in O(n), and if we binary search on the flow values we only have to test log(n) different flow values. Thus we can 
solve this problem with binary search in O(nlog(n)).

*/

bool testFlow(vector<int> a, int x){
    //test whether a certain flow value works by simply looping through the array
    int prev=0;
    bool up = true;
    for(int i=0;i<a.size();i++){
        if(prev==x&&up){
            //if you got to x, you need another x to start going down
            if(a[i]==x){
                up = false;
            }
        }
        else if(up){
            //if you are going up, you need to have seen a[i]-1
            if(prev==a[i]-1){
                prev = a[i];
            }
        }else{
            //if you are going down, you need to have seen a[i]+1
            if(prev==a[i]+1){
                prev = a[i];
            }
        }
    }
    
    //the flow exists if you got all the way down to 1
    return prev==1&&!up;
}

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
        
        int low=0; //start with flow that always works
        int high=n/2+1; //start with flow that never works
        //we continue searching until it works for low and doesn't work for low+1
        while(high!=low+1){

            int mid = (low+high)/2;
            
            if(testFlow(a,mid)){
                //low will store the highest flow that works
                low = mid;
            }else{
                //high will store the lowest flow that doesn't work
                high = mid;
            }

        }

        //the answer is low because it stores the highest value that works
        cout<<low<<endl;
    }

}

