#include <bits/stdc++.h>
using namespace std;

// the bits/stdc++.h header includes a lot of helpful built in tools
// for C++, and the using namespace std helps you from writing the
// std:: prefix in front of some of these built in things

int main(){
    // num test cases
    int a;
    cin >> a;

    // floop over every test case and solve for each individually
    // as they come in
    for(int testNum = 0; testNum < a; ++testNum){
        // number of paintings, and number of paintings Maxie must buy
        int n, x;
        cin >> n >> x;

        // grab our arrays from input

        vector<int> tessOffers(n);
        for(int i = 0; i < n; ++i){
            cin >> tessOffers[i];
        }

        vector<int> maxieOffers(n);
        for(int i = 0; i < n; ++i){
            cin >> maxieOffers[i];
        }

        // a couple of things to note: there are some possibly
        // deceiving greedy approaches to this problem that are not
        // comprehensive. Some include choosing the x paintings with
        // the biggest maxieOffers values and giving the remaining paintings
        // to Tess, and others that will fall short of an exhaustive solution

        // our goal is to maximize the sum of offers from Tess + the sum of offers
        // from Maxie while obeying each painting is gotten by exactly one of the two
        // and x of them go to Maxie

        // our solution will be using the following steps: we will first
        // give all of our paintings to Tess; then there are x paintings we need
        // to take away from Tess and instead give to Maxie; we can compute how much
        // this swap from Tess to Maxie of painting number i will affect our sum of offers;
        // specifically, making this swap of painting i will add exactly
        // (maxieOffers[i] - tessOffers[i]) to our total sum; we will call this value for
        // painting number i delta[i]; we will want to greedily take the x biggest deltas
        // to maximize our total sum; note that some of these values can be negative, in which
        // case we will still be maximizing our answer, as we must switch ownership of exactly
        // x paintings (for example, if we had to take one delta between -1 and -10, we would
        // choose the -1 as it hurts us the least)

        int totalSum = 0;
        // give all to Tess initially
        for(int i = 0; i < n; ++i){
            totalSum += tessOffers[i];
        }

        // now let's compute our deltas
        vector<int> deltas(n);
        for(int i = 0; i < n; ++i){
            // value for taking this painting from Tess and giving to Maxie
            deltas[i] = maxieOffers[i] - tessOffers[i];
        }

        // we will sort our list so that the x biggest things can be easily found at the back
        sort(begin(deltas), end(deltas));

        // add the x biggest deltas to totalSum
        for(int num = 0; num < x; ++num){
            // the position in our list will be num back from the last position of deltas
            int idx = n - 1 - num;

            totalSum += deltas[idx];
        }

        // print our answer
        cout << totalSum << "\n";
    }

    return 0;
}
