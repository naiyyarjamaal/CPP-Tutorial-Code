// Flatten a binary tree..
/*given a binary tree flatten it into linked list in place. After flattering left of each node should point to NULL
and right should contain next node in preorder sequence...
(Not allowed to use another data structure)
*/
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

void flattenBT(node* root){         // this function is not working . Try once again......

    if(root == NULL || ((root->left == NULL) && (root->right == NULL))){
        return;
    }

    if(root->left != NULL){
        flattenBT(root->left);

        node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node* t = root->right;
        while(t->right != NULL){
            t = t->right;
        }

        t->right = temp;
    }

    flattenBT(root->right);

}

void inorderPrint(node* root){
    if(root==NULL){
        return;
    }

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    flattenBT(root);
    inorderPrint(root);

    return 0;
}