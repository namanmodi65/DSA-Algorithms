#include <bits/stdc++.h> 

void solve(string s,int idx,string output,vector<string> &ans){
    if(idx>=s.size()){
        if(output.size() > 0) ans.push_back(output);
        return ;
    }

    //exclude (Not take)
    solve(s,idx+1,output,ans);
    //include (take)
    output.push_back(s[idx]);
    solve(s,idx+1,output,ans);

}

vector<string> subsequences(string str){
	
	vector<string> ans;
    solve(str,0,"",ans);
    return ans;
	
}
