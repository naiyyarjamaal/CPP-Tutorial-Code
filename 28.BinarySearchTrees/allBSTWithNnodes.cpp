// consructing the all possible bst using the n number of nodes..
#include<iostream>
#include<vector>
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

vector<node*> constructTrees(int start, int end){

    vector<node*> trees;

    if(start > end){
        trees.push_back(NULL);
        return trees;
    }

    for(int i=start; i<=end; i++){
        vector<node*> leftSubtrees = constructTrees(start, i-1);
        vector<node*> rightSubtrees = constructTrees(i+1, end);
        for(int j=0; j<leftSubtrees.size(); j++){
            node* left = leftSubtrees[j];
            for(int k=0; k<rightSubtrees.size(); k++){
                node* right = rightSubtrees[k];
                node* Node = new node(i);
                Node->left = left;
                Node->right = right;
                trees.push_back(Node);
            }
        }
    }

    return trees;

}

void printPreorder(node* root){
    if(root==NULL){
        return ;
    }

     cout<<root->data<<" ";
     printPreorder(root->left);
     printPreorder(root->right);
}


int main(){
    
    vector<node*> totalTrees = constructTrees(1, 5);

    for(int i=0; i<totalTrees.size(); i++){
        cout<<(i+1)<<" : ";
        printPreorder(totalTrees[i]);
        cout<<endl;
    }

    return 0;
}