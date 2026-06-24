class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) 
    {
        int n=arr.size();
        int i=0 , j=0;
        int m = dep.size();
        int useplatform=0;
        int maxplatform=0;
        sort(arr.begin() , arr.end());
        sort(dep.begin() , dep.end());
        while(i<n && j<m)
        {
            if(arr[i]<=dep[j])
            {
                useplatform++;
                maxplatform=max(maxplatform , useplatform);
                i++;
            }
            else
            {
                useplatform--;
                j++;
            }
        }
        return maxplatform;
        
        
    }
};
