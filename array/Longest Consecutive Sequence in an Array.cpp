class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr)
    {
        int n= arr.size();
        unordered_set<int> st(arr.begin() , arr.end());
        int maxi=0;
        
        for(int x:st)
        {
            if(st.find(x-1)==st.end())
            {
                int count=1;
                int current =x;
            
            
            while(st.find(current+1)!=st.end())
            {
                count++;
                current++;
            }
            
            maxi=max(maxi,count);
            }
        }
        return maxi;
        
        
        

    }
};
