#include<iostream>
using namespace std;

int fact(int n){
    if(n==0 || n==1){
        return 1;
    }

    return n*fact(n-1);
}

void pascalTriangle(int n){

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            int ans = fact(i)/(fact(i-j)*fact(j));
            cout<<ans<<" ";
        }cout<<endl;
    }

}



int main(){
    int n;
    cin>>n;

    pascalTriangle(n);


    return 0;
}