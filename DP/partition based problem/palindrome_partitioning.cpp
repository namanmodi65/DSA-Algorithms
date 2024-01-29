#include<bits/stdc++.h>
bool isValid(string s,int i,int j){
    while(i<j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;

}

int solve(int i,string &s,int n,vector<int> &dp){
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];

    int minCost = INT_MAX;
    for(int j=i;j<n;j++){
        if(isValid(s,i,j)){
            int cost = 1+solve(j+1,s,n,dp);
            minCost = min(minCost,cost);
        }
    }
    return dp[i]=minCost;
}

int palindromePartitioning(string str)
{
    // Write your code here
    vector<int> dp(str.size()+1,-1);
    return solve(0,str,str.size(),dp)-1;
}
