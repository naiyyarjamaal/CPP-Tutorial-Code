// write a program to check if a given number is power of twu using bit manipulation..

#include<iostream>
using namespace std;

bool isPowerOfTwo(int n){
    
    return (n && !(n & n-1));
}



int main(){
    
    cout<<isPowerOfTwo(16)<<endl;
    cout<<isPowerOfTwo(10)<<endl;
    cout<<isPowerOfTwo(164)<<endl;
    cout<<isPowerOfTwo(256)<<endl;


    return 0;
}