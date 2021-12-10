// constructing BST using preorder...

#include<iostream>
#include<climits>
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

node* BSTFromPreorder(int preorder[], int* preorderIdx, int key, int min, int max, int n){

    if(*preorderIdx >= n){
        return NULL;
    }
    node* root = NULL;
    if(key > min && key < max){
        root  = new node(key);
        *preorderIdx = *preorderIdx + 1;

        if(*preorderIdx < n){
            root->left = BSTFromPreorder(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        if(*preorderIdx < n){
            root->right = BSTFromPreorder(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }

    return root;
}
  
void printPreorder(node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){

    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderIdx = 0;
    node* root = BSTFromPreorder(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    
    printPreorder(root);


    return 0;             
}