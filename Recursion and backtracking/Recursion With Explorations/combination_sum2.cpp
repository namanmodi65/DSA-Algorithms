#include<bits/stdc++.h>
void solve(vector<int> &arr,int target,int idx,vector<int>&output,vector<vector<int>> &ans){
	if(target == 0){
		ans.push_back(output);
		return ;
	}

	for(int i=idx;i<arr.size();i++){
		if(i>idx && arr[i]==arr[i-1]) continue;

		if(arr[i]>target) break;

		output.push_back(arr[i]);
		solve(arr,target-arr[i],i+1,output,ans);
		output.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
	vector<int> output;
	solve(arr,target,0,output,ans);
	return ans;
}
