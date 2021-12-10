// queue Using stack...

#include<iostream>
#include<stack>
using namespace std;

class queue{

    stack<int> s1;
    stack<int> s2;

    public:
    
    void push(int x){ 
        s1.push(x);
    }

    int pop(){          // O(n)
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty.."<<endl;
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        int topVal = s2.top();
        s2.pop();

        return topVal;
    }

    bool empty(){
        if(s1.empty() && s2.empty()){
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