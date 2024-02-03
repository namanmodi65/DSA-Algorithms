#include<bits/stdc++.h>

long long solve(long *arr,int n,int idx,bool buy,vector<vector<long long>> &dp){
    if(idx == n) return 0;
    if(dp[idx][buy] != -1) return dp[idx][buy];

    long long profit = 0;

    if(buy){
        profit = max(-arr[idx]+solve(arr,n,idx+1,0,dp) , solve(arr,n,idx+1,1,dp));
    }
    else{
        profit = max(arr[idx]+solve(arr,n,idx+1,1,dp) , solve(arr,n,idx+1,0,dp));
    }

    return dp[idx][buy] = profit;
}



long getMaximumProfit(long *values, int n)
{
    //Write your code here
    //  1 -> buy
    //  0 -> sell
    vector<vector<long long>> dp(n+1,vector<long long>(3,-1));
    return solve(values,n,0,1,dp);
}