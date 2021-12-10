#include<iostream>
#include<string>
using namespace std;

int binaryToDecimal(int n){
    int ans = 0;
     int x = 1;
     while(n>0){
         int y = n%10;
         ans+=x*y;
         x*=2;
         n/=10;
    }
    return ans;
}

int octalToDecimal(int n){
    int ans = 0;
     int x = 1;
     while(n>0){
         int y = n%10;
         ans+=x*y;
         x*=8;
         n/=10;
    }
    return ans;
}

int hexaDecimalToDecimal(string s){
    int ans = 0;
     int x = 1;
     int n= s.size();
     for(int i=n-1; i>=0; i--){
         if(s[i]>='0' && s[i]<='9'){
             ans += x*(s[i]-'0');
         }
         else if(s[i]>='A' && s[i]<='F'){
             ans+= x*(s[i]-'A' + 10);
         }

         x*=16;
     }
    return ans;
}

int decimalToBinary(int n){
    int ans=0;
    int x=1;
    while(x<=n){
        x*=2;
    }
    x/=2;

    while(x>0){
        int last = n/x;
        n-=last*x;
        x/=2;
        ans= ans*10 + last;
    }

    return ans;
}


int decimalToOctal(int n){
    int ans=0;
    int x=1;
    while(x<=n){
        x*=8;
    }
    x/=8;

    while(x>0){
        int last = n/x;
        n-=last*x;
        x/=8;
        ans= ans*10 + last;
    }

    return ans;
}

string decimalToHexadecimal(int n){
    string ans="";
    int x=1;
    while(n<=n){
        x*=16;
    }
    x/=16;

    while(x>0){
        int last = n/x;
        n-= last*x;
        x/=16;

        if(last<=9){
            ans= ans + to_string(last);
        }else{
            char ch = 'A' + last - 10;
            ans.push_back(ch);
        }
    }
    return ans;
}

int main(){
    int binary, octal, decimal;
    string str;
    cin>>binary>>octal>>str>>decimal;

    cout<<binaryToDecimal(binary)<<" ";
    cout<<octalToDecimal(octal)<<" ";
    cout<<hexaDecimalToDecimal(str)<<" ";
    cout<<decimalToBinary(decimal)<<" ";

    return 0;
}