#include<iostream>
using namespace std;



int main(){
    int a = 10; 
    int* aptr = &a;

    cout<<aptr<<endl;
    cout<<*aptr<<endl;
    cout<<&a<<endl;

    *aptr = 29;
    // aptr++;

    cout<<aptr<<endl;
    cout<<*aptr<<endl;
    cout<<&a<<endl;

    // pointers as arrays.
    int arr[] = {12, 34, 23 , 56};
    cout<<*arr<<endl;

    int *ptr = arr;
    for(int i=0; i<4; i++){
        // cout<<*ptr<<endl;
        // ptr++;

        cout<<*(arr+i)<<endl;
        // arr++;      // illegal

    }



    return 0;
}