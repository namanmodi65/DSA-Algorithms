int mod = 1e9+7;
int solve(vector<int>& arr, int k, int index, vector<vector<int>>&dp){
	if (index == arr.size()) {
		if(k==0) return 1;
		return 0;
	}

	if(dp[index][k]!=-1) return dp[index][k];
	int take = 0;
	if(k>=arr[index]) take = solve(arr, k-arr[index], index+1, dp)%mod;
	int skip = solve(arr, k, index+1, dp)%mod;

	return dp[index][k] = (take + skip)%mod;
}

int findWays(vector<int>& arr, int k){
	int n = arr.size();
	vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
	return solve(arr, k, 0, dp)%mod;
}