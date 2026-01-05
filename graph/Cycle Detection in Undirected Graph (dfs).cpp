class Solution {
public:
    bool dfs(int node, int parent, int vis[], vector<int> adj[])
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfs(it, node, vis, adj))
                    return true;
            }
            else if (it != parent)
            {
                return true;  // cycle detected
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges)
    {
        vector<int> adj[V];

        // build adjacency list
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int vis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, vis, adj))
                    return true;
            }
        }
        return false;
    }
};

