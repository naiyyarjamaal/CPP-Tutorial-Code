// genrate all substrings of a string with ascii numbers..

#include<iostream>
using namespace std;

void ascciiSubstr(string s, string ans){

    if(s.length()==0){

        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);

    ascciiSubstr(ros, ans+ch);
    ascciiSubstr(ros, ans);
    ascciiSubstr(ros, ans+to_string(code));
}

int main(){
    string str = "AB";

    ascciiSubstr(str, "");

    return 0;
}