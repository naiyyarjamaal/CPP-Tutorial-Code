// traverse and print zig zag traversal of binary trees...
// right to left
// left to right and so on
// means we r doing level order traversal from right the left then right then so on..

#include<iostream>
#include<stack>
using namespace std;

class node{
    public:
        node* right;
        node* left;
        int data;

        node(int val){
            data = val;
            right = NULL;
            left = NULL;
        }
}; 

void zigZagTraversal(node* root){  // O(n)

    if(root==NULL){
        return;
    }
    stack<node*> currLevel;
    stack<node*> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);

    while (!currLevel.empty()) {
        node* temp = currLevel.top();
        currLevel.pop();

            if(temp){ // checking if not null
                cout<<temp->data<<" ";
            

            if(leftToRight){ // cheking if not null
                if(temp->left){
                    nextLevel.push(temp->left);
                }

                if(temp->right){
                    nextLevel.push(temp->right);
                }
            }
            // for right to left traversal ...
            else{

                if(temp->right){
                    nextLevel.push(temp->right);
                }

                if(temp->left){
                    nextLevel.push(temp->left);
                }
            }
        }
        if(currLevel.empty()){
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
    
}

int main(){

    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);

    // test
    zigZagTraversal(root);
    cout<<endl;
    


    return 0;
}