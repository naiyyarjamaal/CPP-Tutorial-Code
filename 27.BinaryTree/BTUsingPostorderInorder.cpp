// build tree using data given as postorder and inorder of a tree.
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

int search(int inorder[], int start, int end, int cval){
    for(int i=start; i<=end; i++){
        if(inorder[i]==cval){
            return i;
        }
    }
    return -1;  //this case never encountered
}

node* buildTree(int postorder[], int inorder[], int start, int end){// here start and end represent the starting and ending postion of inorder array
    static int idx = end; // it track the index of postorder from its end.

    if(start>end){
        return NULL;
    }

    int val = postorder[idx];
    idx--;
    node* curr = new node(val);
    if(start==end){
        return curr;
    }

    int pos = search(inorder, start,  end, val); // index position of inorder
    curr->right = buildTree(postorder, inorder, pos+1, end);
    curr->left = buildTree(postorder, inorder, start, pos-1);

    return curr;
}

void inorderPrint(node* root){
    if(root==NULL){
        return ;
    }

    inorderPrint(root->left);
    cout<<root->data<<"  ";
    inorderPrint(root->right);
}



int main(){
    

    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};

    node* res = buildTree(postorder, inorder, 0, 4);
    inorderPrint(res);


    return 0;
}