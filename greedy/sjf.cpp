class Solution {
  public:
    int solve(vector<int>& bt) 
    {
        int n=bt.size();
        sort(bt.begin(), bt.end());
        int wt=0;
        int ans=0;
        for(int i=0 ; i<n-1 ; i++)
        {
            wt=wt+bt[i];
            ans=ans+wt;
            
        }
        ans=(ans/n) ;
        return ans;
        
        
    }
};
