int NthRoot(int n, int m) {
  // Write your code here.
  int start = 1;
  int end = m/2;
  long long mid=(start+end)/2;

  while(start<=end){
    
    if(pow(mid,n) == m) return mid;
    
    if(pow(mid,n)> m) end = mid-1;
    else start = mid+1;

    mid = start+(end-start)/2;
  }
  return -1;
}