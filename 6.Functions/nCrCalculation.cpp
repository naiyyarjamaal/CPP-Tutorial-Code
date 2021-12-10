#include<iostream>
using namespace std;

int fact(int n){
    if(n==0 || n==1){
        return 1;
    }

    return n*fact(n-1);
}

int nCr(int n, int r){
    return fact(n)/(fact(n-r)*fact(r));
}

int main(){
    int n, r;
    cin>>n>>r;

    cout<<nCr(n, r)<<endl;


    return 0;
}