#include<iostream>
using namespace std;



int main(){
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int savings;
    cin>>savings;

    if(savings>5000){
        cout<<"Go for party in a five star hotel"<<endl;

    }
    else{
        cout<<"Organise party at the home"<<endl;
    }

    return 0;
}