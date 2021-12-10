// finding maximum possible sum of a path in a binary tree, starting and ending node

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

int maxPathSumUtil(node* root, int &ans){

    if(root==NULL){
        return 0;
    }

    int leftSum = maxPathSumUtil(root->left, ans);
    int rightSum = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data+leftSum+rightSum), max(root->data+leftSum, root->data+rightSum));

    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data+leftSum, root->data+rightSum));

    return singlePathSum;
}

int maxPathSum(node* root){

    int ans = INT8_MIN;

    maxPathSumUtil(root, ans);
    return ans;
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<maxPathSum(root);

    return 0;
}