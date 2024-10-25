#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
const int INF=LLONG_MAX>>1;
int power(int a, int b) {
    if(b == 0) return 1;
    a %= MOD;
    int half_power = power(a, b/2);
    if(b % 2 == 0) {
        return half_power * half_power % MOD;
    } else {
        return half_power * half_power % MOD * a % MOD;
    }
}

double dp[3000][3000];
int n;
double solve(int idx,int head,vector<double> &arr){
    if(idx == n){
        if(head>(n-head)) return 1;
        return 0;
    }

    if(dp[idx][head] >= 0) return dp[idx][head];

    double ans = arr[idx]*solve(idx+1,head+1,arr)+(1-arr[idx])*solve(idx+1,head,arr);
    return dp[idx][head] = ans;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int n;
    cin>>n;
    vector<double> arr(n);
    for(auto &i:arr)cin>>i;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,arr)<<endl;
    
   return 0;
}