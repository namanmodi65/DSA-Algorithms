#include <bits/stdc++.h> 

int mod = 1e9+7;

int solve(int idx,vector<int> arr,int n,int target,vector<vector<int>> &dp){
    if(idx == n-1){
        if(target==0 && arr[n-1] == 0) return 2;
        if(target==0 || arr[n-1] == target) return 1;
        else return 0;
    }
    if(dp[idx][target] != -1) return dp[idx][target];
    int include = 0;
    if(arr[idx]<=target){
        include = solve(idx+1,arr,n,target-arr[idx],dp);
    }
    int exclude = solve(idx+1,arr,n,target,dp);
    return dp[idx][target] =(include+exclude)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totalSum = 0;

    for(auto it : arr){
        totalSum += it;
    }

    if(totalSum - d < 0 || (totalSum-d)%2 != 0) return 0;

    int s2 = (totalSum-d)/2;

    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return solve(0,arr,n,s2,dp);
}


