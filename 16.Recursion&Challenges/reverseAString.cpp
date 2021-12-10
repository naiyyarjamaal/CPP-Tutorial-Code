// reverse a string using recursion..

#include<iostream>
using namespace std;
#include<string>

void reverseStr(string s){

    if(s.length() == 0){
        return;
    }
    string restString = s.substr(1);
    reverseStr(restString);
    cout<<s[0];

}

int main(){
    
   string str ;
   getline(cin, str);
   reverseStr(str);

    return 0;
}