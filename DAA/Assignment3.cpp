// Write a program to solve a 0-1 Knapsack problem using dynamic programming or branch and bound strategy.

#include <iostream>
#include<vector>
using namespace std;


int func(int i,int W,vector<int>wt,vector<int>&val,vector<vector<int>>&dp){
    if(i<0||W<0)return 0;
    if(dp[i][W]!=-1)return dp[i][W];
    int pick=0;
    if(W>=wt[i])pick=val[i]+func(i-1,W-wt[i],wt,val,dp);
    int nopick=func(i-1,W,wt,val,dp);
    return dp[i][W]=max(pick,nopick);
}
int knapSack(vector<int>wt,vector<int>&values,int W){
    int n=wt.size();
    vector<vector<int>>dp(n,vector<int>(W+1,-1));
    return func(n-1,W,wt,values,dp);
}



int main(){
    
    int W=12;
    // vector<int> wt={2,4,6,9}; 
    // vector<int> val={10,10,12,18};

    vector<int> wt={5,7,4,2}; 
    vector<int> val={30,28,20,24};

    // cout<<knapSack(wt,val,W);


    return 0;
}