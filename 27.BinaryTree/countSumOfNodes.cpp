// count sum of nodes present in a binary tree... 
// sum of all nodes in the binary tree...
#include<iostream>
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

int countNodes(node* root){

    if(root==NULL){
        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumAllNodes(node* root){
    if(root==NULL){
        return 0;
    }

    return sumAllNodes(root->left) + sumAllNodes(root->right) + root->data;
}



int main(){
    
    node* root = new node(1);
    root->left= new node(2);
    root->right= new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<countNodes(root)<<endl;
    cout<<sumAllNodes(root)<<endl;


    return 0;
}