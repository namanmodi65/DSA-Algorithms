void bubbleSort(vector<int>& arr, int n)
{   
    for(int i=0;i<n-1;i++){
        bool swapped = false; // this is used for optimization
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            return;
        }
    }
}
