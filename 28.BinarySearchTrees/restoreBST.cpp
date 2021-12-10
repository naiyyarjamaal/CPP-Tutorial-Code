/*
Problem:
2 nodes of a BST are swapped. Our task is to restore(correct) the binary search tree...
*/
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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointers(node* root, node** first, node** mid, node** last, node** prev){
    if(root==NULL){
        return;
    }

    calcPointers(root->left, first, mid, last, prev);

    if(*prev && root->data < (*prev)->data){
        if(!*first){// if first is null
            *first = *prev;
            *mid = root;
        }
        else{
            *last = root;
        }
    }

    *prev = root;
    calcPointers(root->right, first, mid, last, prev);
}


void restoreBST(node* root){
    node *first, *mid, *last, *prev;
    first = mid = last = prev = NULL;

    calcPointers(root, &first, &mid, &last, &prev);

    // case 1
    if(first && last){ // not null
        swap(&(first->data), &(last->data));
    }
    // case 2
    else if(first && mid){
        swap(&(first->data), &(mid->data));
    }
}


void printInorder(node* root){
    if(root == NULL){
        return ;
    }

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);

}


int main(){
    
    /*
    correct BST
                             6
                            / \
                           3    9
                          / \     \
                         1   4     13

    Voilating BST after swapped from above BST
                             6
                            / \
                           9    3
                          / \     \
                         1   4     13
    */

   node* root = new node(6);
   root->left = new node(9);
   root->right = new node(3);
   root->left->left = new node(1);
   root->left->right = new node(4);
   root->right->right = new node(13);

   printInorder(root);
   cout<<endl;

   restoreBST(root);

   printInorder(root);
   cout<<endl;

    return 0;
}