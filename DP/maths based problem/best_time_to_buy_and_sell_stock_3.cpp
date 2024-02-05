#include<bits/stdc++.h>

int solve(vector<int>&arr,int n,int idx,bool buy,int count,vector<vector<vector<int>>> &dp){
    if(idx == n) return 0;
    if(count == 0) return 0;
    if(dp[idx][buy][count-1] != -1) return dp[idx][buy][count-1];

    int profit = 0;

    if(buy){
        profit = max(-arr[idx]+solve(arr,n,idx+1,0,count,dp) , solve(arr,n,idx+1,1,count,dp));
    }
    else{
        profit = max(arr[idx]+solve(arr,n,idx+1,1,count-1,dp) , solve(arr,n,idx+1,0,count,dp));
    }

    return dp[idx][buy][count-1] = profit;
}

int maxProfit(vector<int>& prices)
{
    // Write your code here.
    //  1 -> buy
    //  0 -> sell
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(2,-1)));
    return solve(prices,n,0,1,2,dp);
}