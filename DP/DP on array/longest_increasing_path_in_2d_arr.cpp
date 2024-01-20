#include <bits/stdc++.h> 
bool isValid(int row,int col,int n,int m){
    return ((row>=0 && row<n) && (col>=0 && col<m));
}

int solve(int i,int j,vector<vector<int>> &mat, int n, int m,vector<vector<int>>&dp){
    if(!isValid(i,j,n,m)) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int ans = 1;
    
    if((j-1>=0 && j-1<m) && mat[i][j-1]>mat[i][j]){
        ans = max(ans,1+solve(i,j-1,mat,n,m,dp));
    }
    if( (j+1>=0 && j+1<m) && mat[i][j+1]>mat[i][j]){
        ans = max(ans,1+solve(i,j+1,mat,n,m,dp));
    }
    if( (i-1>=0 && i-1<n) && mat[i-1][j]>mat[i][j]){
        ans = max(ans,1+solve(i-1,j,mat,n,m,dp));
    }
    if( (i+1>=0 && i+1<n) && mat[i+1][j]>mat[i][j]){
        ans = max(ans,1+solve(i+1,j,mat,n,m,dp));
    }

    return dp[i][j] = ans;
}

int longestIncreasingPath(vector<vector<int>> &mat, int n, int m)
{
    int ans = 1;
    vector<vector<int>>dp(n,vector<int>(m,-1));
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans = max(ans,solve(i,j,mat,n,m,dp));
        }
    }
    return ans;
}