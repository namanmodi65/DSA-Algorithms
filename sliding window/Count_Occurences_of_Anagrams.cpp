int search(string pat, string s) {
	    // code here
	    int k = pat.size();
	    unordered_map<char,int> mp;
	    for(auto i:pat) mp[i]++;
	    int cnt = mp.size();
	    int i=0;
	    int j=0;
	    int ans = 0;
	    while(j<s.size()){
	        if(mp.find(s[j]) != mp.end()){
	            mp[s[j]]--;
	            if(mp[s[j]] == 0) cnt--;
	        }   
	        if(j-i+1<k) j++;
	        else if(j-i+1 == k){
	            if(cnt == 0){
	                ans++;
	            }
	            if(mp.find(s[i]) != mp.end()){
	                mp[s[i]]++;
	                if(mp[s[i]]==1){
	                    cnt++;
	                }
	            }
	            i++;
	            j++;
	        }
	    }
	    return ans;
	}