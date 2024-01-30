
int solve(vector<int> &arr, int k,int i,int n,vector<int> &dp){
    if(i == n )return 0;
    if(dp[i] != -1) return dp[i];

    int ans = INT_MIN;
    int len = 0;
    int maxi = INT_MIN;

    for(int j=i;j<min(n,i+k);j++){
        len++;
        maxi = max(maxi,arr[j]);
        int sum = (len*maxi)+solve(arr,k,j+1,n,dp);
        ans = max(ans,sum);
    }
    return dp[i] = ans;
    
}

int maximumSubarray(vector<int> &arr, int k){
    // Write your code here.
    vector<int> dp(arr.size()+1,-1);
    return solve(arr,k,0,arr.size(),dp);
}