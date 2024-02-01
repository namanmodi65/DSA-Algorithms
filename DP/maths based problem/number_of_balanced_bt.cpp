#include <bits/stdc++.h> 


long long mod = 1e9+7;

int solve(int n,vector<int> &dp){
    if(n==1 || n==0) return 1;
    if(dp[n] != -1) return dp[n];

    return dp[n]=(solve(n-1,dp)*(solve(n-1,dp)+(2*solve(n-2,dp))%mod)%mod)%mod;
}

int countBalancedBinaryTree( int n)
{
    //    Write your code here.
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}