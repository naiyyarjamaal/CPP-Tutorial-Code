#include<iostream>
#include<set>
using namespace std;



int main(){

// ordered SET
    // set
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    for(auto i : s){
        cout<<i<<" ";
    }cout<<endl;
    cout<<s.size()<<endl;
    s.erase(2);
     for(auto i : s){
        cout<<i<<" ";
    }cout<<endl;

    // multiset..
    cout<<"\nMultiset...\n";
    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(2);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);
    ms.insert(4);
    for(auto i : ms){
        cout<<i<<" ";
    }cout<<endl;
    cout<<ms.size()<<endl;
    ms.erase(ms.find(2));
     for(auto i : ms){
        cout<<i<<" ";
    }cout<<endl;
    ms.erase(2);
    for(auto i : ms){
        cout<<i<<" ";
    }cout<<endl;


// Unordered set
    


    return 0;
}