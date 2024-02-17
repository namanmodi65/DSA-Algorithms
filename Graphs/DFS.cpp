void DFS(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs)
{
    vis[node] = 1;
    dfs.push_back(node);
    for (auto i : adj[node])
    {
        if (vis[i] != 1)
        {
            DFS(i, adj, vis, dfs);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V, 0);
    int start = 0;
    vector<int> dfs;
    DFS(start, adj, vis, dfs);
    return dfs;
}