bool detectCycleUsingDFS(int node,int parent,vector<int> adj[],vector<int> &vis){
        vis[node]=1;
        for(auto i:adj[node]){
            if(vis[i] != 1){
                if(detectCycleUsingDFS(i,node,adj,vis)==true) return true;
            }
            else if(i!=parent) return true;
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        //DFS
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i] == 0){
                if(detectCycleUsingDFS(i,-1,adj,vis)) return true;
            }
        }
        return false;
    }