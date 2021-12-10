/*
for given root nodes of 2 binary search trees. print if the BSTs are identical or not.
Identical BSTs are structurally identical & have equal values for the nodes in the structure..
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


// check for the given two BSTs are identical..
bool isIdnetical(node* root1, node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }

    else if(root1==NULL || root2==NULL){
        return false;
    }
    // when both of the roots are not null, in which we r dealing with three conditions
    else{
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdnetical(root1->left, root2->left);
        bool cond3 = isIdnetical(root1->right, root2->right);

        if(cond1 && cond2 && cond3){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    
    node* root = new node(2);
    root->left = new node(1);
    root->right = new node(3);


    node* root2 = new node(6);
    root2->left = new  node(3);
    root2->right = new node(10);

//////////////////////////////////////////////////////////////////////
    if(isIdnetical(root, root)){
        cout<<"BSTs are identical"<<endl;
    }
    else{
        cout<<"BSTs are not identical."<<endl;
    }

////////////////////////////////////////////////////////////////////
    if(isIdnetical(root, root2)){
        cout<<"BSTs are identical"<<endl;
    }
    else{
        cout<<"BSTs are not identical."<<endl;
    }

    return 0;
}