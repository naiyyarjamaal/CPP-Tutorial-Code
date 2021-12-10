// check the given tree is bst or not
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

// check for bst
bool isBST(node* root, node* min = NULL, node* max = NULL){  // O(n)..

    if(root == NULL){
        return true;
    }

    if(min != NULL && root->data <= min->data){
        return false;
    }

    if(max != NULL && root->data >= max->data){
        return false;
    }

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);

    return (leftValid and rightValid);
}

int main(){
    
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);

    if(isBST(root, NULL, NULL)){
        cout<<"The given tree is a valid Binary trees.."<<endl;
    }
    else{
        cout<<"The given tree is not a valid Binary trees.."<<endl;
    }


    return 0;
}