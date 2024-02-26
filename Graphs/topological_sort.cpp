	void dfsTopologicalSort(int node,vector<int> &vis,vector<int> adj[],stack<int> &s){
	    vis[node]=1;
	    for(auto i:adj[node]){
	        if(vis[i]==0){
                dfsTopologicalSort(i,vis,adj,s);
                s.push(i);
	        }
	    }
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> s;
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(vis[i] == 0){
	            dfsTopologicalSort(i,vis,adj,s);
	            s.push(i);
	        }
	    }
	    vector<int> ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}