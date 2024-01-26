#include<bits/stdc++.h>
long solve(int *denominations, int n, int value,int idx,vector<vector<long>> &dp){
    if(value == 0) return 1;
    if(idx>=n || value<0){
        return 0;
    }
    if(dp[idx][value] != -1) return dp[idx][value];

    long ans = 0;

    // include
    ans += solve(denominations,n,value-denominations[idx],idx,dp);
    //exclude
    ans += solve(denominations,n,value,idx+1,dp);

    return dp[idx][value]=ans;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n+1,vector<long>(value+1,-1));
    return solve(denominations,n,value,0,dp);
    //Write your code here
}