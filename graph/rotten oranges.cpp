class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();       //row
        int m=grid[0].size();    //col
        queue<pair<int,int>> rotten;
        int time=0 , fresh=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j]==2) rotten.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        int rx[4]={-1,0,1,0};
        int cx[4]={0,1,0,-1};

        while(!rotten.empty() && fresh>0)
        {
            int k=rotten.size();
            time++;
            while(k--)
            {
                int x=rotten.front().first;
                int y=rotten.front().second; 
                rotten.pop();
                for(int i=0 ; i<4 ; i++)
                {
                    int nr=x+rx[i];
                    int nc=y+cx[i];

                     if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc]==1)
                     {
                        grid[nr][nc]=2;
                        rotten.push({nr,nc});
                        fresh--;
                     }
                }

            }
        }
        if (fresh == 0) return time;
        else return -1;
        
    }
};
