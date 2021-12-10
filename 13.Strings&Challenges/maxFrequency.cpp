// find the maximum occurance of a character in a string 
#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;



int main(){
    
    string s = "fkadsfjda fsafjadfdasffaa affalfajfja";
    int freq[26];
    for(int i=0; i<26; i++){
        freq[i] = 0;
    }

    for(int i=0; i<s.size(); i++){
        freq[s[i]-'a']++;
    }
    char ans;
    int maxFrq = INT_MIN;

    for(int i=0; i<26; i++){
        // maxFrq = max(maxFrq, freq[i]);
        if(freq[i] > maxFrq){
            maxFrq = freq[i];
            ans = i+'a';
        }
    }

    cout<<ans<<"    "<<maxFrq<<endl;


    return 0;
}