class Solution {
public:
    void solve(int idx,vector<int> &arr,int target,vector<int> &output,vector<vector<int>> &ans){
    if(idx == arr.size() ){
        if(target == 0){
            ans.push_back(output);
        }
        return ;
    }

    if(arr[idx] <= target){
        output.push_back(arr[idx]);
        solve(idx,arr,target-arr[idx],output,ans);
        output.pop_back();
    }

    solve(idx+1,arr,target,output,ans);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> a;
        solve(0,candidates,target,a,ans);
        return ans;
    }
};