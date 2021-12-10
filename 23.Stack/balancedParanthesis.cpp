// to find the given string has balanced paranthesis or not..

#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    int n = s.size();

    stack<char> st;
    bool ans = true;

    for(int i=0; i<n; i++){
        char ch = s[i];

        if(ch=='(' || ch=='[' || ch=='{'){
            st.push(ch);
        }

        // if(st.empty()){
        //     ans = false;
        //     break;
        // }

        else if(ch==')'){
            if(!st.empty() && st.top()=='('){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }

        else if(ch==']'){
            if(!st.empty() && st.top()=='['){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }

        else if(ch=='}'){
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
    }

    if(!st.empty()){
        return false;
    }

    return ans;
}

int main(){
    
    string s = "{([])})";

    if(isValid(s)){
        cout<<"Valid String"<<endl;
    }
    else{
        cout<<"Invalid String"<<endl;
    }

    return 0;
}