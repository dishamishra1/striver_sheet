class Solution {
public:
    long long totalhours(vector<int>& piles, int hourly)
    {
        long long totalh=0;
        int n=piles.size();
        for(int i=0 ; i<n ; i++)
        {
            totalh += (piles[i] + hourly - 1) / hourly;
        }
        return totalh;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1 ;
        int maxpile = *max_element(piles.begin(), piles.end());
        int high=maxpile;
        int ans;
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long totalhrs= totalhours(piles,mid);
            if(totalhrs<=h) 
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return ans;


        
    }
};
