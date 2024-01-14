void rec(int n, string &s, int open, int close, int i,vector<string> &ans){
    if ((open == close) and (open == n)){
        ans.push_back(s);
        return;
    }
    else if (open == close){
        s[i] = '(';
        rec(n, s, open + 1, close, i + 1,ans);
    }
    else{
        if (open < n){
            s[i] = '(';
            rec(n, s, open + 1, close, i + 1,ans);
        }
        if (close < n){
            s[i] = ')';
            rec(n, s, open, close + 1, i + 1,ans);
        }
    }
}

 

vector<string> validParenthesis(int n)
{
    string s(2 * n, '.');
    s[0] = '(';
    vector<string> ans;
    rec(n, s, 1, 0, 1,ans);
    return ans;

}