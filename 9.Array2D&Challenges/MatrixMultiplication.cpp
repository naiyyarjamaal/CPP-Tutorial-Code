#include<iostream>
using namespace std;



int main(){


    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int l, m, n;
    cin>>l>>m>>n;

    int a[l][m];
    int b[m][n];

    int ans[l][n];

    for(int i=0; i<l; i++){
        for(int j=0; j<m; j++)
            cin>>a[i][j];
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cin>>b[i][j];
    }

    for(int i=0; i<l; i++){
        for(int j=0; j<n; j++)
            ans[i][j] = 0;
    }

    for(int i=0; i<l; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                ans[i][j]+=  a[i][k] * b[k][j];
            }
        }
    }


    for(int i=0; i<l; i++){
        for(int j=0; j<n; j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    

    return 0;
}