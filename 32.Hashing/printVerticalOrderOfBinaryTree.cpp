// print the vertical order of binary tree ,
// given the input of binary tree using array representation at level order traversal


// this code is not working look at in free time...

#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<string> 
using namespace std;


// define int long long
#define vi vector<int>
#define pii pair<int , int>
#define vii vector<pii>
#define rep(i, a, b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)


class node{
    public:
        node *left, *right;
        int key;

        node(int val){
            key = val;
            left = NULL;
            right = NULL;
        }
};

void getVerticalOrder(node* root, int hrzntlDist, map<int, vector<int>> m){

    if(root==NULL){
        return ;
    }

    m[hrzntlDist].push_back(root->key);
    getVerticalOrder(root->left, hrzntlDist-1, m);
    getVerticalOrder(root->right, hrzntlDist+1, m);

}

int main(){
    
    node* root = new node(10);
    root->left = new node(7);
    root->right = new node(4);
    root->left->left = new node(3);
    root->left->right = new node(11);
    root->right->left = new node(14);
    root->left->right = new node(6);

    map<int, vector<int>> mp;
    int horizontalDist =0;

    getVerticalOrder(root, horizontalDist, mp);

    map<int, vi> :: iterator it;
    for(it = mp.begin(); it!=mp.end(); it++){
        for(int i=0; i<(it->ss).size(); i++){
            cout<<(it->ss)[i]<<"    ";
        }cout<<endl;
    }
    return 0;
}