// building stack using array

#include<iostream>
#define n 100
using namespace std;


class Stack{
    int* arr;
    int top;

    public:
    Stack(){
        arr = new int[n];
        top = -1;
    }


    void push(int x){

        if(top==n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }

        top++;
        arr[top] = x;
    }

    void pop(){
        if(top==-1){
            cout<<"No element to pop"<<endl;
            return;
        }

        top--;
    }

    int Top(){
        if(top==-1){
            cout<<"No element to return form stack"<<endl;
            return -1;
        }

        return arr[top];
    }

    bool empty(){
        // if(top == -1){
        //     return true;
        // }
        // return false;

        return top==-1;
    }
};



int main(){
    Stack st;
    st.push(23);
    st.push(78);
    st.push(12);
    cout<<st.Top()<<endl;
    cout<<st.empty()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();


    return 0;
}