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

int n,m;
int arr[501][501];
int dp[501][1024];
bool solve(int row,int prev){
    if(row == n){
        if(prev>0) return true;
        return false;
    }
    if(dp[row][prev] != -1) return dp[row][prev];
    bool ans = false;
    for(int i=0;i<m;i++){
            ans = ans||solve(row+1,arr[row][i]^prev);
    }
    return dp[row][prev]=ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    if(solve(0,0) == true){
        cout<<"TAK";
    }
    else cout<<"NIE"<<endl;
   return 0;
}