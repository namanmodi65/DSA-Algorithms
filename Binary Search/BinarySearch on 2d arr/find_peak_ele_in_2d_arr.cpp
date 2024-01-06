#include<bits/stdc++.h>
int maxEle(vector<vector<int>> &g,int n,int col){
    int max = INT_MIN;
    int idx = -1;
    for(int i=0;i<n;i++){
        if(g[i][col] > max){
            idx = i;
            max = g[i][col];
        }
    }
    return idx;
}

vector<int> findPeakGrid(vector<vector<int>> &g){
    // Write your code here.
    int n = g.size();    
    int m = g[0].size(); 

    int start = 0;
    int end = m-1;
    int mid = start+(end-start)/2;
    while(start<=end){
        int row = maxEle(g,n,mid);
        int left = mid-1>=0?g[row][mid-1]:-1;
        int right = mid+1<m?g[row][mid+1]:-1;
        if(left<g[row][mid] && g[row][mid]>right) return {row,mid};

        if(g[row][mid]<left) end = mid-1;
        else start = mid+1;

        mid = start+(end-start)/2;
    }
    return {-1};
}