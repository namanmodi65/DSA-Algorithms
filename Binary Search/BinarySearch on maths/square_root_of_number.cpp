int floorSqrt(int n)
{
    // Write your code here.
    if(n<2) return n;

    int ans = 0;
    int start = 0;
    int end = n/2;
    int mid = start+(end-start)/2;
    while(start<=end){
        if(((long long)mid*mid) > n){
            end = mid-1;
        }
        else{
            ans = mid;
            start = mid+1;
        }
        mid = start+(end-start)/2;
    }
    return ans;

}
