// build tree using data given as preorder and inorder of a tree.
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


int search(int inorder[], int start, int end, int curr){
    for(int i=start; i<=end; i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;  //this case never encountered
}

node* buildTree(int preorder[], int inorder[], int start, int end){// here start and end represent the starting and ending postion of inorder array

    static int idx=0; // idx iterate with index of preorder array

    if(start>end){
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    node* resNode = new node(curr);

    if(start == end){
        return resNode;
    }

    int pos = search(inorder, start, end, curr); // store the position of curr ptr of inorder.
    resNode->left = buildTree(preorder, inorder, start, pos-1);
    resNode->right = buildTree(preorder, inorder, pos+1, end);

    return resNode;
}

void inoderPrint(node* root){
    if(root==NULL){
        return;
    }

    inoderPrint(root->left);
    cout<<root->data<<"  ";
    inoderPrint(root->right);
}


int main(){
    
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};

    // inoderPrint(buildTree(preorder, inorder,0, 4));
    node* res = buildTree(preorder, inorder,0, 4);
    inoderPrint(res);
    cout<<endl;


    return 0;
}