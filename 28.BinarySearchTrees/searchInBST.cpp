#include<iostream>
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

node* searchInBST(node* root, int key){

    if(root == NULL){
        return NULL;
    }

    if(key == root->data){
        return root;
    }

    if(key>root->data){
       return searchInBST(root->right, key);
    }
        
    return searchInBST(root->left, key);

}



int main(){
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);

    if(searchInBST(root, 7)==NULL){
        cout<<"Given key doesn't exist in the BST"<<endl;
    }
    else{
        cout<<"Given key exist in the BST"<<endl;
    }


    return 0;
}