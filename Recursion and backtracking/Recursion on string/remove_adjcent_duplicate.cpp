string solve(string &s,int i,int n){
    if(i>=n) return "";
    string ans = "";
    ans += s[i];
    char ele =s[i];
    while(i<n && s[i] == ele){
        i++;
    }
    return ans+solve(s,i,n);
}

string removeDuplicate(string &s)
{
    int n = s.size();
    return solve(s,0,n);
}
