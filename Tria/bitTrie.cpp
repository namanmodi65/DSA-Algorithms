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

struct node{
    node *child[2];
    int cnt = 0;
    node(){
        child[0] = NULL;
        child[1] = NULL;
    }
};

struct trie{
    node* root;
    trie(){
        root = new node;
    }

    void insert(int n){
        node* curr = root;
        for(int i=LN-1;i>=0;i--){    //LN CONSTANT HOGI QUE KE ACCORDING 
            curr->cnt++;
            int x = (n&(1<<i))?1:0;
            if(curr->child[x] == NULL){
                curr->child[x] = new node;
            }
            curr = curr->child[x];
        }
        curr->cnt++;
    }
};



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        
    }
    
   return 0;
}