class Solution {
public:
    vector<int> findnse(vector<int>& arr)
    {
        int n=arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1 ; i>=0 ; i--)
        {
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();
            st.push(i);

        }
        return nse;
        
    }
    
    vector<int> findpse(vector<int>& arr)
    {
        int n=arr.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i=0 ; i<n ; i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }


    int sumSubarrayMins(vector<int>& arr) 
    {
        int mod=(int)(1e9+7);
        int n=arr.size();
        long long total=0;
        vector<int> nse=findnse(arr);
        vector<int> pse=findpse(arr);
        for(int i=0 ; i<n ; i++)
        {
            int left= i - pse[i];
            int right= nse[i] - i;
            total= ((total + ((1LL *right * left % mod) * arr[i]) % mod ) % mod);
        }
        return total;

        
    }
};
