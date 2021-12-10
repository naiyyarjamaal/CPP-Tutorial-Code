// convert an infix string into a postfix string...
//traversal starts form beginning of string

#include<iostream>
#include<stack>

using namespace std;


int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    
    return -1;
}

string infixToPostfix(string s){

    stack<char> ch;
    string res;

    for (int i = 0; i < s.length(); i++){
        
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]=='('){
            ch.push(s[i]);
        }
        else if(s[i]==')'){
            while (!ch.empty() && ch.top()!='('){
                res+=ch.top();
                ch.pop();
            }
            if(!ch.empty()){
                ch.pop();
            }
        }
        else{
            while (!ch.empty() && precedence(ch.top())>=precedence(s[i])){
                res+=ch.top();
                ch.pop();
            }
            ch.push(s[i]);
        }
    }

    while(!ch.empty()){
        res+=ch.top();
        ch.pop();
    }
    
    return res;
}




int main(){
    
    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;

    return 0;
}