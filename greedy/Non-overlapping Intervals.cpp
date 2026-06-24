class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int count=0;
        int n=intervals.size();
        sort(intervals.begin() , intervals.end());
        vector<int> temp=intervals[0];
        for(int i=1 ; i< n ; i++)
        {
            vector<int> it = intervals[i];
            if(it[0]<temp[1])
            {
               count++;

               if(it[1]<temp[1])
               {
                  temp=it;
               }
            }
           else
           {
              temp=it;
           }
        }
        return count;
    }
};
