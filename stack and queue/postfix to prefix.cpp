class Solution {
  public:
    string postToPre(string post_exp) 
    {
        stack<string> st;
        for(int i=0 ; i<post_exp.length() ; i++)
        {
            char ch=post_exp[i];
            if(ch>='A'&& ch<='Z' || ch>='a'&& ch<='z' || ch>='0'&& ch<='9')
            {
                st.push(string(1,ch));
            }
            else
            {
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                string con= ch + t2 + t1;
                st.push(con);
            }
        }
        return st.top();
    
        
    }
};
