class Solution {
public:
    void dfs(int row , int col , vector<vector<int>>& image , vector<vector<int>>& ans, 
              int newcolor, int delrow[] , int delcol[], int inicolor)
              {
                ans[row][col]=newcolor;
                int n=image.size();
                int m=image[0].size();
                for(int i=0 ; i<4 ; i++)
                {
                    int nr= row+delrow[i];
                    int nc= col+delcol[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && image[nr][nc]==inicolor && 
                         ans[nr][nc] != newcolor )
                         {
                            dfs(nr,nc,image,ans,newcolor,delrow,delcol,inicolor);
                         }
                }
              }


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        vector<vector<int>> ans=image;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        dfs(sr,sc,image,ans,color,delrow,delcol,inicolor);
        return ans;
    }
};
