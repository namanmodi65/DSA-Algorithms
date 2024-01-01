int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();

	int start = 0;
	int end = n-1;
	int mid = start+(end-start)/2;

	while(start<end){
		if(mid%2 != 0){
			mid--;
		}

		if(arr[mid] != arr[mid+1]){
			end = mid;
		}
		else{
			start = mid+2;
		}
		mid = start+(end-start)/2;
	}
	return arr[start];
}