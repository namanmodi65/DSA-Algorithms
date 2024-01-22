#include<bits/stdc++.h>
bool solve(string a, string b, string c,int i,int j,vector<vector<int>> &dp){
	int k = i+j;
	if(i==a.size() && j==b.size()) return true;
	if(k>=c.size()) return false;
	if(dp[i][j] != -1) return dp[i][j];
	bool ans = false;

	if(i<a.size() && a[i]==c[k]){
		ans = ans||solve(a,b,c,i+1,j,dp);
	} 

	if(j<b.size() && b[j] == c[k]){
		ans = ans||solve(a,b,c,i,j+1,dp);
	}

	return dp[i][j]=ans;
}

bool isInterleave(string a, string b, string c){
	//Your code goes here
	if(c.size()==a.size()+b.size()){
		vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));
		return solve(a,b,c,0,0,dp);
	}
	return false;
}