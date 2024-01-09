
void solve(int N,vector<string> &ans,string bStr,int i){
    if(i == N){
        ans.push_back(bStr);
        return;
    }

    solve(N,ans,bStr+'0',i+1);
    if(i==0 || (i>0 && bStr[i-1] != '1')){
        solve(N,ans,bStr+'1',i+1);
    }
    return ;
}

vector<string> generateString(int N) {
    // Write your code here.
    vector<string> ans;
    solve(N, ans, "", 0);
    return ans;
}