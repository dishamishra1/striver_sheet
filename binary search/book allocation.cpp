class Solution {
  public:
  
  int canbeallot(vector<int> &arr , int pages)
  {
      int stu=1; int pagestu=0;
      for(int i=0 ; i<arr.size() ; i++)
      {
          if(pagestu + arr[i] <= pages)
          {
              pagestu += arr[i];
          }
          else
          {
              stu++;
              pagestu=arr[i];
          }
      }
      return stu;
  }
  
  
  int findPages(vector<int> &arr, int k) {
        // code here
        int low =*max_element(arr.begin(),arr.end());
        int high= accumulate(arr.begin(),arr.end(),0);
        int ans;
        if(arr.size()<k) return -1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(canbeallot(arr,mid)>k) 
            {
                
                 low=mid+1;
            }
            else 
            {
                ans=mid;
                high=mid-1;
            }
        }
        
        return ans;
    }
};
