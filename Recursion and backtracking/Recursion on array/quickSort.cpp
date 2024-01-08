#include <bits/stdc++.h> 

void Swap(vector<int>&arr,int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(vector<int>&arr,int start,int end){
    int pivot=arr[end];
    int i=start-1;
    for(int j=start;j<end;j++){
        if(arr[j]<pivot){
            i++;
            Swap(arr,i,j);
        }
    }
    Swap(arr,i+1,end);
    return i+1 ;
}

void QuickSort(vector<int>&arr,int start,int end){
    if(start<end){
        int pivot = partition(arr,start,end);
        QuickSort(arr,start,pivot-1);
        QuickSort(arr,pivot+1,end);
    }
}

vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    QuickSort(arr,0,arr.size()-1);
    return arr;
}
