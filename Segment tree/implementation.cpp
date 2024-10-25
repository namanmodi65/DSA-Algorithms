
// given an arr and q queies of two type 
// 1. given l and r you have to return the sum between l r
// 2. given idx ans val you have to update the val at idx

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

vector<int> segTree;

void build(vector<int> &arr,int start,int end,int idx){//bulid the segment tree
    // time complexity : o(n)
    if(start == end){
        segTree[idx] = arr[start];
        return;
    }

    int mid = (start+end)/2;
    int left = 2*idx;
    int right = 2*idx+1;
    build(arr,start,mid,left);
    build(arr,mid+1,end,right);
    segTree[idx] = segTree[left]+segTree[right];

}

void update(vector<int> &arr,int start,int end,int idx,int pos,int val){//update at a given point in segment tree
    // time complexity : o(logn)
    if(start == end){
        arr[pos] = val;
        segTree[idx] = arr[pos];
        return ;
    }

    int mid = (start+end)/2;
    if(mid>=pos){
        update(arr,start,mid,2*idx,pos,val);
    }
    else{
        update(arr,mid+1,end,2*idx+1,pos,val);
    }

    segTree[idx] = segTree[2*idx]+segTree[2*idx+1];
}

int query(int start,int end,int idx,int l,int r){//give sum L to R
    // time complexity : o(logn)
    //complete overlap
    if(start>=l && end<=r) return segTree[idx];
    //disJoin
    if(l > end || r < start) return 0;
    int mid = (start+end)/2;
    int leftAns = query(start,mid,2*idx,l,r);
    int rightAns = query(mid+1,end,2*idx+1,l,r);
    return leftAns+rightAns;
}

void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    segTree.resize(2*n);
    for(auto &i:arr) cin>>i;
    build(arr,0,n-1,1);

    // for(auto i:arr){
    //     cout<<i<<" ";
    // }
    cout<<endl;
    for(auto i:segTree){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<query(0,n-1,1,0,2)<<endl;
    update(arr,0,n-1,1,1,3);
    
    for(auto i:segTree){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<query(0,n-1,1,0,2)<<endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    
   return 0;
}