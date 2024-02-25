bool bfs(int start,int V,vector<int> adj[],vector<int> &vis){
        vis[0] = 1;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i:adj[node]){
                if(vis[i] == -1){
                    vis[i] = !vis[node];
                    q.push(i);
                }
                else if(vis[i]==vis[node]) return false;
            }
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V,-1); // -1 se islea initilize kiya h keo ki 1 and 0 are color
	    for(int i=0;i<V;i++){
	        if(vis[i] == -1)
	            if(!bfs(i,V,adj,vis)) return false; 
	    }
	    
	    return true;
	    
	}