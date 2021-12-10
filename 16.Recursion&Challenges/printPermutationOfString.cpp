// print all the permutation of a string...
#include<iostream>
using namespace std;

void printPemtn(string s, string ans){

    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        string ros = s.substr(0,i)+s.substr(i+1);
        printPemtn(ros, ans+ch);

    }
    
}


int main(){
    
    string str = "ABCD";
    printPemtn(str, "");

    return 0;
}