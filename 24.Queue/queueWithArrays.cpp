// Arrays implementation of queue..

#include<iostream>
#define n 100
using namespace std;

class queue{
    int* arr;
    int front; 
    int back;

    public:
    queue(){
        arr = new int[n];
        front=-1;
        back=-1;
    }

    void push(int x){
        if(back==n-1){
            cout<<"QUeue Overflow."<<endl;
            return;
        }
        back++;
        arr[back]=x;

        if(front==-1){
            front++;
        }
    }

    void pop(){
        if(front==-1 || front>back){
            cout<<"No element in queue."<<endl;
            return;
        }

        front++;
    }

    int peek(){
        if(front==-1 || front>back){
            cout<<"No element in queue."<<endl;
            return -1;
        }

        return arr[front];
    }

    bool empty(){
        if(front==-1 || front>back){
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

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();


    return 0;
}