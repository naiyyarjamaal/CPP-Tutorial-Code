// find the max sum of subarray of circular array..
#include<iostream>
#include<climits>
using namespace std;

int kadaneAlgorithm(int a[], int n){
    // now applying kedane's algorithm...
    int currSum = 0;
    int maxSum = INT_MIN;
    for(int i=0; i<n; i++){
        currSum+= a[i];
        if(currSum<0){
            currSum = 0;
        }

        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}



int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int totalSum = 0;
    for(int i=0; i<n; i++){
        totalSum+= a[i];
    }

    
    int wrapSum;
    int nonWrapSum;
    nonWrapSum = kadaneAlgorithm(a, n);

    for(int i=0; i<n; i++){
        a[i] = -a[i];
    }

    wrapSum = totalSum - (-kadaneAlgorithm(a, n));

    cout<<max(wrapSum, nonWrapSum)<<endl;


    return 0;
}