class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int prefixsum=0;
        int count=0;
        int n=nums.size();
        unordered_map<int,int> mpp;
        mpp[0]=1;
        for(int i=0 ; i<n ; i++)
        {
            prefixsum +=nums[i];
            if(mpp.find(prefixsum-k) != mpp.end())
            {
                count+=mpp[prefixsum-k];
            }
            mpp[prefixsum]++;

        }
        return count;
        
    }
};
