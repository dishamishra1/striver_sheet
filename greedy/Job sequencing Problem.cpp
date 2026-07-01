class Solution {
  public:
  static bool cmp(pair<int,int> a , pair<int,int> b)
  {
      return a.second > b.second;
  }
  
   vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) 
    {
        int n=deadline.size();
        vector<pair<int,int>> jobs;
        for(int i=0 ; i<n ; i++)
        {
            jobs.push_back({deadline[i] , profit[i]});
            
        }
        
        sort(jobs.begin() , jobs.end() , cmp);
        
        int maxi=0;
        for(int i=0 ; i< n ; i++)
        {
            maxi=max(maxi , deadline[i]);
        }
       
       vector<int> slot(maxi+1 , -1);
       
       int count=0 ;
       int maxprofit=0;
       for(int i=0 ; i<n ; i++)
       {
           for(int j=jobs[i].first ; j>=1 ; j--)
           {
               if(slot[j]==-1)
               {
               slot[j]=1;
               count++;
               maxprofit += jobs[i].second;
               break;
               }
           }
       }
       return {count,maxprofit};
          
    }
};
