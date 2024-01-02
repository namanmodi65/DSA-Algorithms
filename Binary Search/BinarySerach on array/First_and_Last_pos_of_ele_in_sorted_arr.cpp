#include <bits/stdc++.h> 

int binarySearchStart(vector<int> arr,int size,int target){
        int start = 0;
        int end = size-1;
        int ans =-1;
        int mid = start+(end-start)/2;
        while(start<=end){

            if(arr[mid] == target){
                ans =  mid;
                end = mid-1;
            }
            else if(arr[mid]>target){
                end = mid-1;
            }
            else if(arr[mid]<target){
                start = mid+1;
            }
            mid =  start+(end-start)/2;
        }
        return ans;
}

int binarySearchEnd(vector<int> arr,int size,int target){
        int start = 0;
        int end = size-1;
        int ans =-1;
        int mid = start+(end-start)/2;
        while(start<=end){

            if(arr[mid] == target){
                ans =  mid;
                start = mid+1;
            }
            else if(arr[mid]>target){
                end = mid-1;
            }
            else if(arr[mid]<target){
                start = mid+1;
            }
            mid =  start+(end-start)/2;
        }
        return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int start = binarySearchStart(arr,n,k);
    int end = binarySearchEnd(arr,n,k);
    pair<int, int> ans;
    ans.first = start;
    ans.second = end;
    return ans;
}