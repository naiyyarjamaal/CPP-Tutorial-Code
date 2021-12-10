// queue using stack using recursion in optimised way.

#include<iostream>
#include<stack>
using namespace std;

class queue{

    stack<int> s1;

    public:
    
    void push(int x){ 
        s1.push(x);
    }

    int pop(){          
        if(s1.empty()){
            cout<<"Queue is empty.."<<endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();

        if(s1.empty()){
            return x;
        }

        int item = pop();
        s1.push(x);
        return item;
    }

    bool empty(){
        if(s1.empty()){
            return true;
        }

        return false;
    }
};

int main(){
    queue q;
    q.push(23);
    q.push(45);
    q.push(12);
    q.push(21);

    cout<<q.pop()<<endl;
    q.pop();

    cout<<q.pop()<<endl;
    q.pop();

    cout<<q.pop()<<endl;
    q.pop();

    cout<<q.pop()<<endl;
    q.pop();

    cout<<q.pop()<<endl;
    q.pop();



    return 0;
}