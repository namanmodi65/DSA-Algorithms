// PRIM'S ALGO

int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V,0);
        vector<pair<int,int>> mst;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > q;
        
        q.push({0,{0,-1}});
        int sum = 0;
        while(!q.empty()){
            int wt = q.top().first;
            int node = q.top().second.first;
            int parent = q.top().second.second;
            q.pop();
            if(vis[node] ==1) continue;
            vis[node] = 1;
            sum += wt;
            if(parent == -1){
                for(auto i:adj[node]){
                    if(!vis[i[0]])
                        q.push({i[1],{i[0],node}});
                }
            }
            else{
                mst.push_back({parent,node});
                for(auto i:adj[node]){
                    if(!vis[i[0]])
                        q.push({i[1],{i[0],node}});
                }                
            }
        }
        
        // for(auto i:mst){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        
        return sum;
    }