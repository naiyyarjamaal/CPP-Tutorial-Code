// Implementing stack using queue..
//push method is costly.

#include<iostream>
#include<queue>
using namespace std;

class Stack{
    int n;
    queue<int> s1;
    queue<int> s2;

    public:
    Stack(){
        n=0;
    }

    void push(int val){
        s2.push(val);
        n++;
        while(!s1.empty()){
            s2.push(s1.front());
            s1.pop();
        }

        queue<int> temp = s1;
        s1 = s2;
        s2 = temp;
    }

    void pop(){
        s1.pop();
        n--;
    }

    int top(){
        return s1.front();
    }

    int size(){
        return n;
    }
};

int main(){
    
    Stack s;

    s.push(34);
    s.push(23);
    s.push(45);
    s.push(12);
    s.push(21);

    cout<<s.top()<<endl;
    s.pop();

     cout<<s.top()<<endl;
    s.pop();

     cout<<s.top()<<endl;
    s.pop();

     cout<<s.top()<<endl;

     cout<<s.size()<<endl;

    return 0;
}