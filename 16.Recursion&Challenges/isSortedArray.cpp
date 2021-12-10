// check if an array is sorted or not .. strictly increasing
#include<iostream>
using namespace std;

bool isSorted(int a[], int n){

    if(n==1){
        return true;
    }

    bool restArray = isSorted(a+1, n-1);
    return (a[0]<a[1] && restArray);


}

int main(){
    
    int arr[] = {2, 3, 5, 7, 8, 12, 23,34 ,45, 56};

    cout<<isSorted(arr, 10)<<endl;

    return 0;
}