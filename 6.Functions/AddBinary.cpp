// code is not working .. check once again in free time...
#include<iostream>
using namespace std;

int reverse(int n){
    int ans = 0;
    while(n>0){
        int last = n%10;
        ans = ans*10 + last;
        n/=10;
    }

    return ans;
}

int binarySum(int n1,int n2){
    int ans;
    int prevCarry = 0;

    while (n1>0 && n2>0){
        if(n1%2==0 && n2%2==0){
            ans = ans*10 + prevCarry;
            prevCarry = 0;
        }

        else if((n1%2==1 && n2%2==0) || (n1%2==0 && n2%2==1)){
            ans = ans*10 + prevCarry;
            prevCarry = 0;
            if(prevCarry==1){
                ans = ans*10 + 0;
                prevCarry = 1;
            }

            else{
                ans = ans*10 +1;
                prevCarry = 0;
            }
        }

        else{
            ans = ans*10 + prevCarry;
            prevCarry = 1;
        }

        n1/=10; n2/=10;
    }

    while(n1>0){
        if(prevCarry==1){
            if(n1%2==1){
                ans = ans*10 + 0;
                prevCarry=1;
            }
            else{
                ans = ans*10 + 1;
                prevCarry = 0;
            }
        }
        else{
            ans = ans*10 + (n1%2);
        }
        n1/=10;        
    }

    while(n2>0){
        if(prevCarry==1){
            if(n2%2==1){
                ans = ans*10 + 0;
                prevCarry=1;
            }
            else{
                ans = ans*10 + 1;
                prevCarry = 0;
            }
        }
        else{
            ans = ans*10 + (n2%2);
        }
        n2/=10;        
    }
    
    if(prevCarry == 1){
        ans = ans*10 + 1;
    }

    ans = reverse(ans);

    return ans;
}

int main(){
    int b1, b2;
    cin>>b1>>b2;

    cout<<binarySum(b1, b2)<<" ";
    return 0;
}