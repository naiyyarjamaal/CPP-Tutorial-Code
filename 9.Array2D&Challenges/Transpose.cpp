#include<iostream>
using namespace std;



int main(){
    

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;

    int arr[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    // transpose..
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
            
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout <<arr[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}