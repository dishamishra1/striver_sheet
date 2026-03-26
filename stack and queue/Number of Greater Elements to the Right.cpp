class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) 
    {
     
        int n=arr.size();
        vector<int> ans;
        
        for(int i = 0; i < indices.size(); i++)
        {
            int count=0;
            int idx = indices[i];
            
            for(int j = idx + 1; j < n; j++)
            {
                if(arr[j] > arr[idx])
                {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;

      
        }
        
};
