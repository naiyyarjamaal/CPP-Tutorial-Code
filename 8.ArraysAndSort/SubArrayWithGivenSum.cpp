// find the subarray with given sum..

#include<iostream>
using namespace std;
                //// Do it once again it's not working....


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int sum;
    cin>>sum;
    int i=0, j=0, st=-1, en=-1, currSum=0;

    while(j<n && currSum+a[j] <= sum){
        currSum += a[j];
        j++;
    }

    if(currSum == sum){
        cout<<i+1<<" to "<< j<<endl;
        return 0;
    }

    while(j<n){
        currSum += a[j];
        while (currSum > sum)
        {
            currSum -= a[i];
            i++;
        }
        
        if(currSum==sum){
            st=i+1;
            en=j+1;
            break;
        }
        j++;
    }

    cout<<st<<" to "<<en<<endl;
    return 0;
}