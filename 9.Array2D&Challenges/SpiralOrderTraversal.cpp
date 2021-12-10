
#include<iostream>
using namespace std;



int main(){
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin>>n>>m;

    int arr[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    // Spiral order traversal;
    int r_st =0, r_end = n-1;
    int c_st = 0, c_end = m-1;

    while(r_st<=r_end && c_st<=c_end){
        // for row start;
        for(int col=c_st; col<=c_end; col++){
            cout<<arr[r_st][col]<<" ";
        }cout<<endl;
        r_st++;

        for(int row=r_st; row<=r_end; row++){
            cout<<arr[row][c_end]<<" ";
        }cout<<endl;
        c_end--;

        for(int col=c_end; col>=c_st; col--){
            cout<<arr[r_end][col]<<" ";
        }cout<<endl;
        r_end--;

        for(int row=r_end; row>=r_st; row--){
            cout<<arr[row][c_st]<<" ";
        }cout<<endl;
        c_st++;
    }



    return 0;
}
