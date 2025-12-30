class Solution {
  public:
  
  bool canweplace(vector<int> &stalls , int dist , int cows)
  {
      
      int count=1;
      int last=stalls[0];
      int n=stalls.size();
      for(int i=1 ; i<=n-1 ; i++)
      {
          if((stalls[i]-last)>=dist)
          {
              last=stalls[i];
              count++;
          }
          if(count>=cows) return true;
          else false;
      }
  }
  
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int low=0 ;
        int high=stalls.back() - stalls.front();
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(canweplace(stalls,mid,k)==true)
            {
                low=mid+1;
            }
            else high=mid-1;
        }
        return high;
    }
};
