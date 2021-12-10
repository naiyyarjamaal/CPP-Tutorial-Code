// finding that the given tree is height balanced tree or not..

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

int calcHeight(node* root){
    if(root==NULL){
        return 0;
    }

    return max(calcHeight(root->left), calcHeight(root->right)) + 1;
}

bool isBalanced(node* root){        // O(n^2) here O(n) for each clacHeight 


    if(root == NULL){
        return true;
    }

    if(isBalanced(root->left) == false){
        return false;
    }
    if(isBalanced(root->right) == false){
        return false;
    }

    int lh = calcHeight(root->left);
    int rh = calcHeight(root->right);

    if(abs(lh-rh)<=1){
        return true;
    }else{
        return false;
    }
}

bool isBalancedOptimized(node* root, int* height){ // O(n)..

    if(root==NULL){
        return true;
    }
    int lh=0, rh=0;
    if(isBalancedOptimized(root->left, &lh)==false){
        return false;
    }
    if(isBalancedOptimized(root->right, &rh)== false){
        return false;
    }

    *height = max(lh, rh) + 1;

    if(abs(lh-rh)<=1){
        return true;
    }else{
        return false;
    }
}

int main(){

    // for balanced input..
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);  


    // for unbalnced input..
    node* root1 = new node(1);
    root1->left = new node(2);
    root1->left->left = new node(3);
    root1->left->left->left = new node(4);
    root1->left->left->left->left = new node(5);

    cout<<isBalanced(root)<<endl;
    if(isBalanced(root)){
        cout<<"Balanced Tree"<<endl;
    }else{
        cout<<"Unbalanced Tree"<<endl;
    }

    if(isBalanced(root1)){
        cout<<"Balanced Tree"<<endl;
    }else{
        cout<<"Unbalanced Tree"<<endl;
    }

    int height = 0;
    cout<<"Using optimized code"<<endl;
    if(isBalancedOptimized(root, &height)){
        cout<<"Balanced Tree"<<endl;
    }else{
        cout<<"Unbalanced Tree"<<endl;
    }

    if(isBalancedOptimized(root1, &height)){
        cout<<"Balanced Tree"<<endl;
    }else{
        cout<<"Unbalanced Tree"<<endl;
    }


    return 0;
}