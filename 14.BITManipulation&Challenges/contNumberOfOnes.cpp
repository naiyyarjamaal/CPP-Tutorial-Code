// cout the total number of ones in the binary representation

#include<iostream>
using namespace std;

int countNumberOfOnes(int n){
    int cnt = 0;
    while(n!=0){
        n = n & (n-1);
        cnt++;
    }

    return cnt;
}

int main(){
    
    cout<<countNumberOfOnes(19)<<endl;

    return 0;
}