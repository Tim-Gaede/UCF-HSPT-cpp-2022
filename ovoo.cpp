//2022 UCF HSPT - Ovoo? What's That?
//Author - Tyler Marks

#include <bits/stdc++.h>

using namespace std;

int main(){
    //Scan in the number of clans (test cases)
    int numClans; cin >> numClans;

    //loop through each clan
    for(int clan = 1; clan <= numClans; clan++){
        //output clan number
        cout << "Clan #" << clan << ":\n";

        int numDays, totWork = 0, favor = 0;
        // scan in number of days
        cin >> numDays;

        //loop through dats
        while(numDays--){
            //scan in what task is done on the current day
            string task;
            cin >> task;
            
            //If the task is work, increment totWork
            if(task == "WORK"){
                totWork++;
            }
            //If the task is worship, add totWork to favor and print out favor
            else{
                favor += totWork;
                cout << favor << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}