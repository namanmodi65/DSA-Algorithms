vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        deque<int> cnt;
        
        int i=0;
        int j=0;
        
        while(j<n){
            while(cnt.size()>0 && cnt.back()<arr[j]){
                cnt.pop_back();
            }
            cnt.push_back(arr[j]);
            
            if(j-i+1<k) j++;
            else if(j-i+1 == k){
                ans.push_back(cnt[0]);
                if(cnt[0] == arr[i]){
                    cnt.pop_front();
                }
                i++;
                j++;
            }
        }
        
        return ans;
        
    }