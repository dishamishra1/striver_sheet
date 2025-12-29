class Solution {
public:
     
    int sumofD(vector<int>& nums , int val)
    {
        int sum=0;
        int n=nums.size();
        for(int i=0 ; i <n ; i++)
        {
            sum += ceil((double)nums[i]/ (double)val);
        }
        return sum;
     }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(sumofD(nums,mid)<=threshold)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
    }
};
