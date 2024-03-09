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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector< pair< int,pair<int,int> > > edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt,{node,adjNode}});
            }
        }
        
        DisjointSet ds(V);
        
        sort(edges.begin(),edges.end());
        
        int mstWt = 0;
        for(auto i:edges){
            int wt = i.first;
            int u = i.second.first;
            int v = i.second.second;
            
            if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                mstWt += wt;
                ds.unionByRank(u,v);
            }
        }
        
        
        return mstWt;
    }
};