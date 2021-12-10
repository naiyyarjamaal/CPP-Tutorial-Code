#include<iostream>
using namespace std;



int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int ans = 2;// maitain the maxm length of arithmetic subarray.
    int pd = a[1] - a[0];//previous difference.....
    int j=2;
    int curr = 2; //maintain the currnet subarray length

    while(j<n){
        if(pd == a[j] - a[j-1]){
            j++;
            curr++;
        }

        else{
            pd = a[j] - a[j-1];
            ans = max(ans, curr);
            curr = 2;
            j++;
        }
    }

    cout<<ans<<endl;

    return 0;
}