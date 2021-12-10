// 1.write a program to find a unuque number in an array where all numbers except one, are present.. using bit manipulation..

// 2. Write a program to find two unique number in an array where all numbers except two are present twice...
// using bit manipulatioan

// 3. Write a program to find a unique number in an array where all numbers except one are present thrice;;;;



#include<iostream>         
using namespace std;

//1.solution
int uniqueOneNum(int a[], int n){
    int xorSum = 0;

    for(int i=0; i<n; i++){
        xorSum = xorSum^a[i];
    }

    return xorSum;
}

// 2. Solution

int setBit(int n, int pos){
    return ((n & (1<<pos))!=0);
}

void uniqueTwoNum(int a[], int n){
    int xorSum = 0 ;

    for(int i=0; i<n; i++){
        xorSum = xorSum^a[i];
    }

    int setbit = 0, pos=0;
    int tempXor = xorSum;
    while(setbit!=1){
        setbit = xorSum & 1;
        pos++;

        xorSum = xorSum>>1;
    }

    int newXor = 0;
    for(int i=0; i<n; i++){
        if(setBit(a[i], pos-1)){
            newXor = newXor^a[i];
        }
    }

    cout<<newXor<<endl;
    cout<<(tempXor^newXor)<<endl;
}

// 3. Solution

bool getBit(int n, int pos){
    return  ((n & (1<<pos))!=0);
}

int setBits(int n, int pos){
    return (n | (1<<pos));
}

int unique(int a[], int n){

    int result =0;

    for(int i=0; i<64; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            if(getBit(a[j], i)){
                sum++;
            }
        }
        if(sum%3!=0){
            result = setBits(result, i);
        }
    }
    return result;
}

int main(){
    
    int arr[] = {1, 2, 3, 4, 3, 2, 1};
    cout<<uniqueOneNum(arr, 7)<<endl;

    int a[] = {1,2,3,4,6,3,2,1};
    uniqueTwoNum(a, 8);

    int ar[] = {1,2,3,4,1,2,3,1,2,3};
    cout<<unique(ar, 10)<<endl;
    


    return 0;
}