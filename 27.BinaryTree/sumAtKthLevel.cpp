// level order traversal , and sum at Kth level in binary tree.,
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

void printLevelOrder(node* root){
    if(root==NULL){
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* res = q.front();
        q.pop();

        if(res!=NULL){
            cout<<res->data<<" ";
            if(res->left){
                q.push(res->left);
            }
            if(res->right){
                q.push(res->right);
            }
        }
        
        else if(!q.empty()){
            q.push(NULL);
        }

    }
    

}

int sumAtKthLevel(node* root, int k){
    if(root==NULL){
        return -1;
    }

    queue<node*> q ;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while (!q.empty()){
        node* res = q.front();
        q.pop();

        if(res!=NULL){
            if(level==k)
            sum+=res->data;

            if(res->left)
            q.push(res->left);

            if(res->right)
            q.push(res->right);
        }

        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    
    return sum;
}


int main(){
    
    node* root = new node(1);
    root->left= new node(2);
    root->right= new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    printLevelOrder(root);

    cout<<sumAtKthLevel(root, 2);


    return 0;
}