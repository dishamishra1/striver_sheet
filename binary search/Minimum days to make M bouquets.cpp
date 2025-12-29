class Solution {
public:
    bool possible(vector<int>& bloomDay , int day , int m , int k)
    {
        int count=0; int nob=0;
        int n=bloomDay.size();
        for(int i=0 ; i<n ;i++)
        {
            if(bloomDay[i]<=day) count++;
            else
            {
                nob += (count/k);
                count=0;
            }
        }
        nob += (count/k);
        if(nob>=m) return true;
        else return false;
    }

    
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n=bloomDay.size();
        int ans;
        if(((long)m*k)>n) return -1;
     
        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high=*max_element(bloomDay.begin(), bloomDay.end());
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)==true)
            {
                ans=mid;
                high=mid-1;
             }
             else
             {
                low=mid+1;
             }
        }
        return ans;

        
    }
};
