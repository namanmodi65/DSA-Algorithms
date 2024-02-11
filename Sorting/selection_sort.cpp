void selectionSort(vector<int>& arr, int n)
{   
    for(int i=0;i<n-1;i++){
        int minIdx = i;
        for(int j=i;j<n;j++){
            if(arr[minIdx]>arr[j]){
                minIdx = j;
            }
        }
        if(i != minIdx)
            swap(arr[i],arr[minIdx]);
    }
}