// getting the list of nodes data from a binary tree when the binary tree is viewed from right side of the tree..

#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct  node* right;
     
     node(int val){
         data = val;
         left = NULL;
         right = NULL;
     }
};

void rightView(node* root){   // O(n)
    if(root==NULL){
        return;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()){

        int n = q.size();  // number of nodes present in the root
        for(int i=0; i<n; i++){
            node* curr = q.front();
            q.pop();

            if(i==n-1){
                cout<<curr->data<<" ";
            }

            if(curr->left != NULL){
                q.push(curr->left);
            }

            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);  

    // right view..
    rightView(root);




    return 0;
}
