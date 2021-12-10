#include<iostream>
using namespace std;



int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }cout<<endl;
    }
cout<<endl;

//After inverting the pyramid by 180 degree. (mirror image)
    for(int i=1; i<=n; i++){
        for(int j=n; j>0; j--){
            if(j<=i){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }cout<<endl;
    }

    return 0;
}