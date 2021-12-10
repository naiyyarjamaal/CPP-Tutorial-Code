// generate all substrings of a string..

#include<iostream>
using namespace std;

void allSubstring(string s, string ans){

    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    string ros = s.substr(1); // ros = rest of string

    allSubstring(ros, ans);
    allSubstring(ros, ans+ch);
}

int main(){
    
    string str = "ABC";
    allSubstring(str, "");


    return 0;
}