// V is the number of nodes

// adj[] is the list

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vis[0]=1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto i:adj[node]){
                
                if(vis[i]!=1){
                    vis[i]=1;
                    q.push(i);
                }
                
            }
        }
        return bfs;
    }