class Solution {
public:
    bool detect(int src, vector<vector<int>>& adj, vector<int>& vis) {

        queue<pair<int,int>> q;
        q.push({src, -1});
        vis[src] = 1;

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if(it != parent) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        // 🔹 Convert edge list to adjacency list
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};
