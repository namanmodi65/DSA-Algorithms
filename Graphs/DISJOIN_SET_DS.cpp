#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int ult_u = findUltimateParent(u);
        int ult_v = findUltimateParent(v);
        if(ult_u==ult_v) return ;

        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v ;
        }
        else if(rank[ult_u] > rank[ult_v]){
            parent[ult_v] = ult_u;
        }
        else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }

    }

    void unionBySize(int u,int v){
        int ult_u = findUltimateParent(u);
        int ult_v = findUltimateParent(v);
        if(ult_u==ult_v) return ;
        
        if(size[ult_u]<size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u]+=size[ult_v];
        }
    }

};

int main(){
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findUltimateParent(1)==ds.findUltimateParent(7)) cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;
    ds.unionBySize(3,7);
    if(ds.findUltimateParent(1)==ds.findUltimateParent(7)) cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;
    
    
    
    // DisjointSet ds(7);
    // ds.unionByRank(1,2);
    // ds.unionByRank(2,3);
    // ds.unionByRank(4,5);
    // ds.unionByRank(6,7);
    // ds.unionByRank(5,6);
    // if(ds.findUltimateParent(1)==ds.findUltimateParent(7)) cout<<"Yes"<<endl;
    // else cout<<"NO"<<endl;
    // ds.unionByRank(3,7);
    // if(ds.findUltimateParent(1)==ds.findUltimateParent(7)) cout<<"Yes"<<endl;
    // else cout<<"NO"<<endl;

    return 0;
}