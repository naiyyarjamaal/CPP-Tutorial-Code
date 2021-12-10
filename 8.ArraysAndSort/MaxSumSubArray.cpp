#include<iostream>
#include<climits>
using namespace std;



int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int maxSum = INT_MIN;

    for(int i=0; i<n; i++){     // brute force approach.. O(n^3)
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum+= a[k];
            } 
            maxSum = max(sum, maxSum);
        }
    }
    cout<<maxSum<<endl;
    

    // Cumulitive sum approach.. O(n^2)
    cout<<"\nBy cumulitive sum approach.."<<endl;
    int currSum[n+1];
    currSum[0] = 0;
    for(int i=1; i<=n; i++){
        currSum[i] = currSum[i-1] + a[i-1];
    }

    maxSum = INT_MIN;
    for(int i=1; i<=n; i++){
        int sum = 0;
        for(int j=0; j<i; j++){
            sum = currSum[i] - currSum[j];
            maxSum = max(sum, maxSum);
        }
    }
    cout<<maxSum<<endl;

    // using Kadane's algorithm.. O(n)
    cout<<"\nUsing Kadane's algorithm"<<endl;
    int currentSum =0;
    maxSum = INT_MIN;
    for(int i=0; i<n; i++){
        currentSum+= a[i];
        if(currentSum<0){
            currentSum = 0;
        }

        maxSum = max(maxSum, currentSum);
    }

    cout<<maxSum<<endl;
    return 0;
}