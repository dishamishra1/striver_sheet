class Solution {
  public:
    string postToInfix(string &exp) 
    {
        string ans=" ";
        stack<string> st;
        
        for(int i=0 ; i<exp.length() ; i++)
        {
           char ch=exp[i];
           if(ch>='A' && ch<='Z' || ch>='a' && ch<='z' || ch>='0' && ch<='9')
           {
               st.push(string(1,ch));
           }
           else
           {
               string t1=st.top();
               st.pop();
               string t2=st.top();
               st.pop();
               string con = "(" + t2 +ch + t1 + ")";
               st.push(con);
           }
        }
        return st.top();
        
    }
};
