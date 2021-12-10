#include<iostream>
#include<string>
using namespace std;



int main(){
    string str;
    getline(cin, str);
    cout<<str<<endl;
    string s1="hello", s2="good";
    // s1.append(s2);
    // cout<<s1<<endl;
    cout<<s1+s2<<endl;
    cout<<s2.compare(s1)<<endl;

    return 0;
}