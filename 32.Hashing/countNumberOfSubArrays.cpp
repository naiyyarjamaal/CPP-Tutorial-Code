// count the total number of sub arrays  with sum zero

// we are solving here using prefix sum.. 

#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<string> 
using namespace std;


// define int long long
#define vi vector<int>
#define pii pair<int , int>
#define vii vector<pii>
#define rep(i, a, b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)




int main(){
    
    int n; 
    cin>>n;

    vi a(n);
    rep(i,0,n)
        cin>>a[i];

    map<int, int> cnt; // cnt ---> count

    int prefSum = 0;

    rep(i, 0, n){
        prefSum += a[i];
        cnt[prefSum]++;
    }

    int ans=0;
    map<int, int> :: iterator it;

    for(it=cnt.begin(); it!=cnt.end(); it++){
        int c = it->ss;

        ans += (c*(c-1))/2;

        if(it->ff == 0){
            ans+= it->ss;
        }
    }

    cout<<ans<<endl;

    return 0;
}