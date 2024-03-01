vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        q.push({0,S});
        dist[S] = 0;
        while(!q.empty()){
            int node = q.top().second;
            int dis = q.top().first;
            q.pop();
            
            for(auto i:adj[node]){
                int edgeWeight = i[1];    
                int newNode = i[0];
                if( dis+edgeWeight < dist[newNode]){
                    dist[newNode]=dis+edgeWeight;
                    q.push({dist[newNode],newNode});
                }
            }
        }
        return dist;
    }