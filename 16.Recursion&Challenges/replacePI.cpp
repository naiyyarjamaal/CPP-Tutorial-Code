// replace 'pi' with 3.14 in a string

#include<iostream>
#include<string>
using namespace std;

void replacePi(string s){
    if(s.length()==0){
        return;
    }

    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        string restString = s.substr(2);
        replacePi(restString);
    }
    else{
        cout<<s[0];
        string restString = s.substr(1);
        replacePi(restString);
    }
}

int main(){
    
    string str = "pirefeferppipfjdsfopoppifds";

    replacePi(str);
    cout<<endl; 

    return 0;
}