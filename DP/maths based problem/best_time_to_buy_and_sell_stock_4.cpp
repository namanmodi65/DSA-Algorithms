#include <bits/stdc++.h> 

int solve(vector<int> &arr, int n, int Cnt,int idx,bool buy,vector<vector<vector<int>>> &dp){
    if(idx == n) return 0;
    if(Cnt == 0) return 0;
    if(dp[idx][Cnt][buy] != -1) return dp[idx][Cnt][buy];

    int profit = 0;

    if(buy){
        profit = max(-arr[idx]+solve(arr,n,Cnt,idx+1,0,dp),solve(arr,n,Cnt,idx+1,1,dp));
    }
    else{
        profit = max(arr[idx]+solve(arr,n,Cnt-1,idx+1,1,dp),solve(arr,n,Cnt,idx+1,0,dp));
    }

    return dp[idx][Cnt][buy]=profit;
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
    return solve(prices,n,k,0,1,dp);
}
