// reverse a stack without using another stack ..
// using recursion..

#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int ele){

    if(st.empty()){
        st.push(ele);
        return;
    }

    int topEle = st.top();
    st.pop();

    insertAtBottom(st, ele);

    st.push(topEle);
}

void reverseStack(stack<int> &st){

    if(st.empty()){
        return;
    }

    int ele = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st, ele);
}

void display(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}

int main(){
    
    stack<int> st;
    
    st.push(34);
    st.push(56);
    st.push(23);
    st.push(33);
    st.push(12);

    display(st);
    reverseStack(st);
    display(st);

    return 0;
}