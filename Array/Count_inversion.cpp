void merge(long long arr[],ll start,ll mid,ll end){
        ll a[end+1];
        int left = start;
        int right = mid+1;
        int k=0;
        while(left<=mid && right<=end){
            if(arr[left]<=arr[right]){
                a[k] = arr[left];
                k++;
                left++;
            }
            else{
                a[k] = arr[right];
                k++;
                right++;
            }
        }
        
        while(left<=mid){
            a[k] = arr[left];
            k++;
            left++;
        }
        
        while(right<=end){
            a[k] = arr[right];
            k++;
            right++;
        }
        
        for(int i=0;i<=end;i++){
            arr[i] = a[i];
        }
        
    }
    
    void mergeSort(long long arr[],ll start,ll end){
        if(start<end){
            ll mid = (start+end)/2;
            mergeSort(arr,start,mid);
            mergeSort(arr,mid+1,end);
            merge(arr,start,mid,end);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        mergeSort(arr,0,N-1);
        for(int i=0;i<N;i++){
            cout<<arr[i]<<" ";
        }
        return 0;
        
    }