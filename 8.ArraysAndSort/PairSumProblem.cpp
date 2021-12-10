// Check if there exists two elements in an array such that their sum is equal to given k..
#include<iostream>
using namespace std;

// brute force approach..
bool pairSum(int a[], int n, int k){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(k == a[i] + a[j]){
                cout<<i<<" "<<j<<endl;
                return true;
            }
        }
    }
    return false;
}

bool pairSumModified(int a[], int n, int k){
    int i=0, j=n-1;
    while(i<j){
        if(a[i]+a[j] > k){
            j--;
        }
        else if(a[i]+a[j] < k){
            i++;
        }
        else{
            cout<<"Indexes : "<<i<<" "<<j<<endl;
            return true;
        }
    }

    return false;
}

int main(){
    int n, k;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cin>>k;

    cout<<pairSum(a, n, k)<<endl;
    cout<<pairSumModified(a, n, k)<<endl;


    return 0;
}