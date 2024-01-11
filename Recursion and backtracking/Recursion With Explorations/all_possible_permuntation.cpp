
void solve(string s,vector<string>& ans,int index){
    if(index>=s.size()){
        ans.push_back(s);
        return;
    }
    
    for(int j=index;j<s.size();j++){
        swap(s[index],s[j]);
        solve(s,ans,index+1);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans ;
    int index =0;
    solve(s,ans,index);
    return ans;
}