#include <bits/stdc++.h> 



bool isPossible(vector<int> &arr,int n,int m,long long mid){
	long long dayCnt = 1;
	long long totalTime = 0;
	for(int i=0;i<m;i++){
		if(totalTime+arr[i]<=mid){
			totalTime += arr[i];
		}
		else{
			dayCnt++;
			if(dayCnt>n || arr[i]>mid){
				return false;
			}
			totalTime=arr[i];
		}
	}
	return true;
}



long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.

	long long start = 0;
	long long end = 0;
	for(auto i:time){
		end += i;
	}


	long long mid = start+(end-start)/2;
	long long ans = 0;
	while(start<=end){
		if(isPossible(time,n,m,mid)){
			ans = mid;
			end = mid-1;
		}
		else{
			start = mid+1;
		}
		mid = start+(end-start)/2;
	}

	return ans;

}