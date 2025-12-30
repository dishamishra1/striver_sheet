class Solution {
public:
    int totaldays(vector<int>& weights, int cap)
    {
        int load=0 ; int days=1;
        for(int i=0 ; i<weights.size() ; i++ )
        {
            if(load+weights[i]>cap)
            {
                days=days+1;
                load=weights[i];
            }
            else
            {
                load+=weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) 
    {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(totaldays(weights,mid)<=days)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
    }
};
