#include <bits/stdc++.h> 

void solve(int target,vector<vector<int>> &ans,vector<int> &output,int num){
	if(target == 1){
		if(output.size()>1){
			ans.push_back(output);
		}
		return ;
	}

	for(int i=num;i<=target;i++){
		if(target%i == 0){
			output.push_back(i);
			solve(target/i,ans,output,i);
			output.pop_back();
		}
	}
}


vector<vector<int>> factorCombinations(int n) 
{
	vector<vector<int>> ans;
	vector<int> output;
	int num = 2;
	solve(n,ans,output,num);
	return ans;
}