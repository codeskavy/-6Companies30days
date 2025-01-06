#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

int helper(int i,int opt,int k,vector<int>&prices,vector<vector<int>>&dp){

    if(i==prices.size()) return 0;
    if(opt==2*k) return 0;

    if(dp[i][opt]!=-1) return dp[i][opt];

    int profit=0;

    if(opt%2==0){
        int buy=-prices[i]+helper(i+1,opt+1,k,prices,dp);
        int skip=0+helper(i+1,opt,k,prices,dp);
        profit=max(buy,skip);
    }

    else{
        int sell=+prices[i]+helper(i+1,opt+1,k,prices,dp);
        int skip=0+helper(i+1,opt,k,prices,dp);
        profit=max(sell,skip);
    }

    return dp[i][opt]=profit;

}
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
        return helper(0,0,k,prices,dp);
    }
};