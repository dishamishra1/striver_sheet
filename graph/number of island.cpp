class Solution {
  public:
    
    void bfs(int row, int col,vector<vector<int>>& vis , vector<vector<char>>& grid )
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int delrow=-1 ; delrow<=+1 ; delrow++){
                for(int delcol=-1 ; delcol<=+1 ; delcol++)
                {
                    int nr= row+delrow;
                    int nc=col+delcol;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]=='L')
                    {
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
                
            }
        }
    }
  
   int countIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m,0));
        int count=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++)
            {
                if(!vis[i][j] && grid[i][j]=='L')
                {
                    bfs(i,j,vis,grid);
                    count++;
                }
                
            }
        }
        return count;
    }
};


        
