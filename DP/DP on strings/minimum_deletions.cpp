

int solve(int n, string &str, int curr, char prev, vector<vector<int>> &dp)
{
    if (curr == n)
        return 0;
    if (dp[curr][prev - 'a'] != -1)
        return dp[curr][prev - 'a'];

    int include = 0;

    if (str[curr] >= prev){
        include = 1 + solve(n, str, curr + 1, str[curr], dp);
    }
    int exclude = solve(n, str, curr + 1, prev, dp);
    return dp[curr][prev - 'a'] = max(include, exclude);
}

int minDeletions(string &str)
{
    int n = str.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    int lis = solve(n, str, 0, 'a', dp);

    return str.size() - lis;
}