#include<iostream>
using namespace std;



int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int ans = 0; // maintain the number of record breaking days..
    int mx = 0; // maintain  max of all previous elements.

    if(n==1){
        cout<<1<<endl;
        return 0;
    }

    if(a[0]>a[1]){
        ans++;
        mx = a[0];
    }

    for(int i=1; i<n-1; i++){
        if(a[i]>mx && a[i]>>a[i+1]){
            ans++;
            mx = max(mx, a[i]);
        }
    }
    if(a[n-1]>mx){
        ans++;
    }

    cout<<ans<<endl;
    return 0;
}