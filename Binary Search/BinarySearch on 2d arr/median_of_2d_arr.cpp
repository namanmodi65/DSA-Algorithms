#include<bits/stdc++.h>

int upperBound(vector<int> arr,int x,int n){
    int start = 0;
    int end = n-1;
    int ans = n;
    int mid = start+(end-start)/2;
    while(start<=end){
        if(arr[mid]>x){
            ans = mid;
            end = mid-1;
        }
        else{
            start=mid+1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}

int calculate(vector<vector<int>> &matrix,int x){
    int count = 0;
    int n = matrix.size();
    for(int i=0;i<matrix.size();i++){
        count+= upperBound(matrix[i],x,matrix[0].size());
    }
    return count;
}

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    int start = INT_MAX;
    int end = INT_MIN;
    for(int i=0;i<n;i++){
        start = min(start,matrix[i][0]);
    }
    for(int i=0;i<n;i++){
        end = max(end,matrix[i][m-1]);
    }

    int req = (n*m)/2;
    int mid = start+(end-start)/2;
    while(start<=end){
        int smallerEqual = calculate(matrix,mid);
        if(smallerEqual<=req){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    return start;
}