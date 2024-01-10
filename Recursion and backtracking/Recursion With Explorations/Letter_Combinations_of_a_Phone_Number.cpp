
void solve(string s,string output,int idx,vector<string> &ans,string mapping[]){
    if(idx>=s.size()){
        ans.push_back(output);
        return;
    }

    int number = s[idx]-'0';
    string value = mapping[number];

    for(int i=0;i<value.size();i++){
        output.push_back(value[i]);
        solve(s,output,idx+1,ans,mapping);
        output.pop_back();
    }
}

vector<string> combinations(string s){
	vector<string> ans;
    if(s.length()==0)
        return ans;

	string output="";
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(s,output,0,ans,mapping);
    
    return ans;
	
}
