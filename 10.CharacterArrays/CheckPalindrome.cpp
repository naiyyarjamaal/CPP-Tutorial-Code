#include<iostream>
using namespace std;



int main(){

    int n;
    cin>>n;
    char ch[n+1];

    cin>>ch;
    bool check = true;

    for(int i=0; i<n; i++){
        if(ch[i] == ch[n-i-1]){
            check = false;
            break;
        }
    }

    if(check){
        cout<<"Word is a palindrome..";
    }
    else{
        cout<<"Word is not a palindrome..";
    }


    return 0;
}