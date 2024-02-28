vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites)
{
    vector<int> adj[N];
    for (auto i : prerequisites)
    {
        adj[i[1]].push_back(i[0]);
    }

    vector<int> inDegree(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (auto it : adj[i])
        {
            inDegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto i : adj[node])
        {
            inDegree[i]--;
            if (inDegree[i] == 0)
                q.push(i);
        }
    }

    if (ans.size() == N)
        return ans;

    return {};
}