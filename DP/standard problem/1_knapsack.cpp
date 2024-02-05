#include<bits/stdc++.h>
int solve(vector<int> &values, vector<int> &weights, int w,int idx,vector<vector<int>> &dp){
	if(idx == 0){
		if(weights[0]<=w) return values[0];
		else return 0;
	}
	if(	w == 0) return 0;
	if(dp[idx][w] != -1) return dp[idx][w];

	int include = INT_MIN;
	int exclude = 0+solve(values,weights,w,idx-1,dp);
	if(weights[idx]<=w){
		include = values[idx]+solve(values,weights,w-weights[idx],idx-1,dp);
	}

	return dp[idx][w]=max(include,exclude);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
	return solve(values,weights,w,n-1,dp);
}