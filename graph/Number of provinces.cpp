class Solution {
public:
    void dfs(int node , vector<vector<int>>& adjls , vector<int>& vis )
    {
        vis[node]=1;
        for(auto it : adjls[node])
        {
            if(!vis[it])
            {
                dfs(it,adjls,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isconnected) {
        int v=isconnected.size();
        vector<vector<int>> adjls(v);
        for(int i=0 ; i<v ; i++)
        {
            for(int j=0 ; j<v ; j++)
            {
                if(isconnected[i][j]==1 && i!=j)
                {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);

                }
            }
        }
        vector<int> vis(v, 0);
        int count=0;
        for(int i=0 ; i<v ; i++)
        {
            
            if(!vis[i]) 
            {
                count++;
                dfs(i,adjls,vis);
            }
        }
        return count;
        
    }
    
};
