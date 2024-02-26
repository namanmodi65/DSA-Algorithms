vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   //Kahn's Algo(BFS TOPOLOGICAL SORT)
	   vector<int> inDegree(V,0);
	   for(int i=0;i<V;i++){
	       for(auto it:adj[i]){
	           inDegree[it]++;
	       }
	   }
	   
	   queue<int> q;
	   for(int i=0;i<V;i++){
	       if(inDegree[i] == 0) q.push(i);
	   }
	   
	   vector<int> ans;
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       ans.push_back(node);
	       for(auto i:adj[node]){
	           inDegree[i]--;
	           if(inDegree[i] == 0) q.push(i);
	       }
	   }
	   
	   return ans;
	   
	}