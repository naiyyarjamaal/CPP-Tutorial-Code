#include<iostream>
using namespace std;

// given matrix is sorted...

int main(){
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin>>n>>m;
    int arr[n][m];
    int search;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    cin>>search;

    int r=0, c=m-1;
    bool found = false;
    while(r<n && c>=0){
        if(arr[r][c]==search){
            found = true;
            break;
        }
        if(arr[r][c]>search ){
            c--;
        }
        else{
            r++;
        }

    }

    if(found){
        cout<<"Element is found.";
    }else{
        cout<<"Element does not exist.";
    }




    return 0;
}