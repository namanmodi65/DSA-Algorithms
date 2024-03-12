void dfs(int node,vector<int> &vis,vector<vector<int>>& adj,stack<int> &s){
        vis[node] = 1;
        
        for(auto i:adj[node]){
            if(vis[i] == 0){
                dfs(i,vis,adj,s);
            }
        }
        s.push(node);
        
    }
    void DFS(int node,vector<int> &vis,vector<int> adj[]){
        vis[node] = 1;
        
        for(auto i:adj[node]){
            if(vis[i] == 0){
                DFS(i,vis,adj);
            }
        }
        // s.push(node);
        
    }
    
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(V,0);
        stack<int> sortEdges;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,vis,adj,sortEdges);
            }
        }
        
        vector<int> adjT[V];
        
        for(int i=0;i<V;i++){
            vis[i] = 0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        int ans = 0;
          while(!sortEdges.empty()){
            int node = sortEdges.top();
            sortEdges.pop();
            if(vis[node] == 0){
                ans++;
                DFS(node,vis,adjT);
            }
        }
    
        
        return ans;
        
        
    }