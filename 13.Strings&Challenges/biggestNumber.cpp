// form the biggest number from the numeric string..
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



int main(){
    string s = "234187308";
    sort(s.begin(), s.end(), greater<int>()); // greater<char> will also do
    cout<<s<<endl;


    return 0;
}