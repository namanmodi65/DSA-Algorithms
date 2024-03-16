// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &v,int k,int idx,int &ans){
    if(v.size() == 1){
        ans = v[0];
        return ;
    }
    
    idx = (idx+k)%v.size();
    v.erase(v.begin()+idx);
    solve(v,k,idx,ans);
    
}

int main() {
    // Write C++ code here
    // std::cout << "Try programiz.pro";
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
 
    k--;
    int idx = 0;
    int ans= 0;
    solve(v,k,idx,ans);
    cout<<ans<<endl;
    
    return 0;
}