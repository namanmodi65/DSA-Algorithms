#include<bits/stdc++.h>
int solve(string s, string t,int S_idx,int T_idx,vector<vector<int>> &dp){
	if(S_idx==s.size() || T_idx==t.size()) return 0;
	if(dp[S_idx][T_idx] != -1) return dp[S_idx][T_idx];

	int ans = 0;

	if(s[S_idx] == t[T_idx]){
		ans = 1+solve(s,t,S_idx+1,T_idx+1,dp);
	}
	else{
		ans = max(solve(s,t,S_idx+1,T_idx,dp),solve(s,t,S_idx,T_idx+1,dp));
	}

	return dp[S_idx][T_idx]=ans;
}

int lcs(string s, string t)
{
	//Write your code here
	vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
	return solve(s,t,0,0,dp);
}