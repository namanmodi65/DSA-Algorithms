#include<bits/stdc++.h>
bool solve(vector<int> &arr, int n,int idx,int sum,vector<vector<int>>&dp){
	if(idx >= n) return false;
	if(sum<0) return false;
	if(sum == 0) return true;
	if(dp[sum][idx]!=-1) return dp[sum][idx];

	bool include = solve(arr,n,idx+1,sum-arr[idx],dp);
	bool exclude = solve(arr,n,idx+1,sum,dp);

	return dp[sum][idx]=include||exclude;
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int sumValue = accumulate(arr.begin(), arr.end(), 0);
	// cout<<sumValue<<endl;
	if(sumValue%2 != 0) return false;
	int target = sumValue/2;
	vector<vector<int>>dp(target+1, vector<int>(n+1, -1));
	return solve(arr,n,0,target,dp);
}
