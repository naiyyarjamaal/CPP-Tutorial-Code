// Largest BST in a binary tree.,

/*
return the size of the largest BST in a given binary tree...
*/
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

class info{ // store the information of each  node and its subtree
    public:
        int size, max, min, ans;
        bool isBST;
};

info largestBSTinBT(node* root){

    if(root == NULL){
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if(root->left==NULL && root->right==NULL){
        return {1, root->data, root->data, 1, true};
    }

    info leftInfo = largestBSTinBT(root->left);
    info rightInfo = largestBSTinBT(root->right);

    info curr; // defines the information of the current root..
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max<root->data && rightInfo.min>root->data){
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max = max(rightInfo.max, max(leftInfo.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}

int main(){
    
    node* root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);

    cout<<"Largest Binary search tree in given Binary tree: "<<largestBSTinBT(root).ans<<endl;

    return 0;
}