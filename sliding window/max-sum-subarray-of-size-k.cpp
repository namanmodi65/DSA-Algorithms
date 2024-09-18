long maximumSumSubarray(int K, vector<int> &arr , int N){
        // code here 
        long long i = 0;
        long long j = 0;
        long long ans = INT_MIN;
        long long sum = 0;
        while(j<N){
            sum += arr[j];
            
            if(j-i+1<K){
                j++;
            }
            else if(j-i+1 == K){
                ans=max(ans,sum);
                sum -= arr[i];
                i++,j++;
            }
        }
        return ans;
    }