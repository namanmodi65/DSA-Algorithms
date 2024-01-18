#include<bits/stdc++.h>
int solve(vector<int> &houses, int idx, vector<int> &dp) {
	if(idx>=houses.size()) return 0;
	if(dp[idx] != -1) return dp[idx];
	int include = solve(houses, idx+2,dp)+houses[idx];
	int exclude = solve(houses, idx+1,dp);

	return dp[idx]=max(include,exclude);

}

int maxMoneyLooted(vector<int> &houses, int n)
{
	vector<int> dp(n+1,-1);
	return solve(houses,0,dp);

}