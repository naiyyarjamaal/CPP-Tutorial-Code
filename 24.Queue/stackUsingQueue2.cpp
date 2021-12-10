// implementation of stack using queue..
// here pop() operation is costly..

#include<iostream>
#include<queue>
using namespace std;

class Stack{
    int n;
    queue<int> q1;
    queue<int> q2;

    public:
    Stack(){
        n=0;
    }

    void push(int val){
        q1.push(val);
        n++;
    }

    void pop(){
        if(q1.empty()){
            return;
        }

        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        n--;

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int top(){
        if(q1.empty()){
            return -1;
        }
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);
        
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
        
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