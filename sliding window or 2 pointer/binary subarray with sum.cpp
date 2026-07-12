class Solution {
public:
    int countsum (vector<int>& nums, int goal) 
    {
        int l=0 , r=0 , sum =0 , count =0 ;
        int n=nums.size();
        while(r<n)
        {
            if(goal<0) return 0;
            sum += nums[r];
            while(sum>goal)
            {
                sum -= nums[l];
                l++;
            }
            count += r-l+1;
            r++ ;

        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return countsum(nums , goal)- countsum(nums , goal-1);

    }
};
