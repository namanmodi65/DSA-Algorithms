void merge(vector<int>& arr,int start,int mid,int end){
    int len1 = mid-start+1;
    int len2 = end-mid;

    int a[len1];
    int b[len2];

    for(int i=0;i<len1;i++){
        a[i]=arr[start+i];
    }
    for(int i=0;i<len2;i++){
        b[i]=arr[mid+i+1];
    }

    int i=0;
    int j=0;
    int k=start;

    while(i<len1 && j<len2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++,k++;
        }
        else{
            arr[k]=b[j];
            j++,k++;
        }
    }

    while(i<len1){
        arr[k]=a[i];
            i++,k++;
    }
    while(j<len2){
        arr[k]=b[j];
            j++,k++;
    }
}

void MergeSort(vector<int>& arr,int start,int end){
    if(start<end){
        int mid = (start+end)/2;
        MergeSort(arr,start,mid);
        MergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
    return;
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    MergeSort(arr,0,n-1);
}