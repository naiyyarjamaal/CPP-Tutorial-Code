// remove all duplicates from the string using recursion..
// it remove only consecutive duplicates...

#include<iostream>
#include<string>
using namespace std;


string removeDuplicate(string s){
    if(s.length() == 0){
        return "";
    }
    char ch = s[0];
    string ans = removeDuplicate(s.substr(1));

    if(ch==ans[0]){
        return ans;
    }
    return (ch+ans);
}

int main(){
    
    string str = "fhadsffadsfjfdsueuuds";
    cout<<removeDuplicate(str);

    return 0;
}