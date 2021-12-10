// find the first and last occurance of a number in an array..

#include<iostream>
using namespace std;

int firstOccurance(int a[], int n, int i, int key){
    if(i==n){
        return -1;
    }

    if(a[i]==key){
        return i;
    }

    return firstOccurance(a, n, i+1, key);
}

int lastOccurance(int a[], int n, int i, int key){

    if(i==n){
        return -1;
    }

    int res = lastOccurance(a, n, i+1, key);
    if(res!=-1){
        return res;
    }

    if(a[i]==key){
        return i;
    }
    else{
        return -1;
    }
}

int main(){
    
    int arr[] = {4, 2, 1, 2, 5, 2, 7};
    // firstAndLastOcc(arr, )
    cout<<firstOccurance(arr, 7, 0, 2)<<endl;
    cout<<lastOccurance(arr, 7, 0, 2)<<endl;


    return 0;
}