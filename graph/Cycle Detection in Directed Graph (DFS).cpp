class Solution {
  public:
  bool dfs(int node ,vector<vector<int>>& adj , int vis[], int pathvis[])
    {
        vis[node]=1;
        pathvis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
              if(dfs(it,adj,vis,pathvis)==true) return true;
            }
            else if(pathvis[it]) return true;
        }
        pathvis[node]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
          vector<vector<int>> adj(V);
          for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);      // directed edge u → v
        }
        int vis[V]={0};
        int pathvis[V]={0};
        for(int i=0 ; i<V ; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,pathvis)==true) return true;
            }
        }
        return false;
    }
    
    
};
