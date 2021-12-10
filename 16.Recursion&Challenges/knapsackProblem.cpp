// put n items with given weight and value in a knapsack of capacity w to get the maximum total value(in rupees) in the knapsack

#include<iostream>
using namespace std;

int maxValue(int value[], int wt[], int n, int W){

    if(n==0 || W==0){
        return 0;
    }

    if(wt[n-1]>W){
        return maxValue(value, wt, n-1, W);
    }

    int included = maxValue(value, wt, n-1, W-wt[n-1]) + value[n-1];
    int notIncluded = maxValue(value, wt, n-1, W);

    return max(included, notIncluded);


}


int main(){
    
    int wt[] = {10, 20, 30};
    int value[] = {100, 50, 150};
    int W = 50 ;

    cout<<maxValue(value, wt, 3, W)<<endl;


    return 0;
}