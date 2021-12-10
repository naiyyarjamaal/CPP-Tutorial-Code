// finding the lowest common ancestors for given two nodes..

#include<iostream>
#include<vector>
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

bool getPath(node* root, int key, vector<int> &path){

    if(root==NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data == key){
        return true;
    }

    if(getPath(root->left, key, path) || getPath(root->right, key, path)){
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(node* root, int n1, int n2){ // time complexity is greater than O(n).......
    vector<int> path1, path2;

    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
        return -1;
    }

    int pathChange; 
    for(pathChange=0; pathChange<path1.size() && path2.size(); pathChange++){
        if(path1[pathChange] != path2[pathChange]){
            break;
        }
    }
    return path1[pathChange-1];
}

node* LCAOptimized(node* root, int n1, int n2){         // O(n)..

    if(root==NULL){
        return NULL;
    }

    if(root->data==n1 || root->data==n2){
        return root;
    }

    node* leftLCA = LCAOptimized(root->left, n1, n2);
    node* rightLCA = LCAOptimized(root->right, n1, n2);

    if(leftLCA && rightLCA){
        return root;
    }
    if(leftLCA!=NULL){
        return leftLCA;
    }

    return rightLCA;
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    int n1=7, n2=6;
    int lca1 = LCA(root, n1, n2);

    node* lca2 = LCAOptimized(root, n1, n2); 

    if(lca1==-1){
        cout<<"LCA doesn't exist."<<endl;
    }
    else{
        cout<<"LCA : "<<lca1<<endl;
    }

    if(lca2==NULL){
        cout<<"LCA doesn't exist."<<endl;
    }
    else{
        cout<<"LCA : "<<lca2->data<<endl;
    }
    return 0;
}