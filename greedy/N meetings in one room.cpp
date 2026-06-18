class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f)
    {
        int n = s.size();
       vector<pair<int , pair<int,int>>> meeting;
       for(int i=0 ; i<n ; i++)
       {
           meeting.push_back({f[i] , {s[i] , i+1}});
       }
       
       sort(meeting.begin() , meeting.end());
       
       vector<int> ans;
       
       int lastmeet=meeting[0].first;
       ans.push_back(meeting[0].second.second);
       
       for(int i=1 ; i<n ; i++)
       {
           int startmeet=meeting[i].second.first;
           if(lastmeet<startmeet)
           {
                ans.push_back(meeting[i].second.second);
                lastmeet=meeting[i].first;
           }
         
       }
       sort(ans.begin(), ans.end());
       return ans;
        
    }
};
