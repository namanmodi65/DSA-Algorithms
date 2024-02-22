bool detect(int src, vector<int> adj[],vector<int> &vis){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto i:adj[node]){
                if(vis[i] != 1){
                    vis[i] = 1;
                    q.push({i,node});
                }
                else if(i != parent){
                    return true;   
                }
            }
        }
        return false;
    } 
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vis[0] = 1;
        for(int i=1;i<V;i++){
            if(vis[i] == 0){
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;
    }