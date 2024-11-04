//------------------------------------------   es ka matbal m yaha change karke tree convert ho sakta h dusre que ko solve karne ke lea


// given an arr and q queies of two type 
// 1. update range by making all value equal to x
// 2. give range xor

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

vector<int> segTree,lazy;

int merge(int a,int b){
    // return min(a,b);
    return a^b;
}

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
    segTree[idx] = merge(segTree[left],segTree[right]);

}

void propogate(int start,int end,int idx){
    if(start == end){
        lazy[idx] = -1;
        return ;
    } //leaf node
    lazy[2*idx] = lazy[idx];
    lazy[2*idx+1] = lazy[idx];
    lazy[idx] = -1;
}

void update(int start,int end,int idx,int l,int r,int val){//update at a given point in segment tree
    // time complexity : o(logn)
    
    if(lazy[idx] != -1){
        segTree[idx] = lazy[idx] * ((end-start+1)&1);//-----------------------------------
        propogate(start,end,idx);
    }

    if(start>=l && end<=r){////complete overlap
        segTree[idx] = val * ((end-start+1)&1);//--------------------------------
        lazy[idx] = val;
        propogate(start,end,idx);
        return;
    }

    if(start>r || end<l) return ; //disjoin
    int mid = (start+end)/2;
    update(start,mid,2*idx,l,r,val);
    update(mid+1,end,2*idx+1,l,r,val);

    segTree[idx] = merge(segTree[2*idx],segTree[2*idx+1]);
}

int query(int start,int end,int idx,int l,int r){//give sum L to R
    // time complexity : o(logn)

    if(lazy[idx] != -1){
        segTree[idx] = lazy[idx]* ((end-start+1)&1);//-----------------------------------
        propogate(start,end,idx);
    }

    //complete overlap
    if(start>=l && end<=r) return segTree[idx];
    //disJoin
    if(l > end || r < start) return 0;//----------------------------------
    int mid = (start+end)/2;
    int leftAns = query(start,mid,2*idx,l,r);
    int rightAns = query(mid+1,end,2*idx+1,l,r);
    return merge(leftAns,rightAns);
}

void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    segTree.resize(4*n,-1);
    lazy.resize(4*n,-1);
    for(auto &i:arr) cin>>i;
    build(arr,0,n-1,1);

    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:segTree){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:lazy){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<query(0,n-1,1,0,3)<<endl;
    update(0,n-1,1,0,3,3);
    cout<<query(0,n-1,1,0,3)<<endl;
    update(0,n-1,1,0,2,3);
    // cout<<query(0,n-1,1,0,2)<<endl;
    // for(auto i:segTree){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(auto i:lazy){
    //     cout<<i<<" ";
    // }
    cout<<query(0,n-1,1,0,3)<<endl;
    for(auto i:segTree){
        cout<<i<<" ";
    }
    // cout<<endl;
    // cout<<endl;
    // cout<<endl;


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