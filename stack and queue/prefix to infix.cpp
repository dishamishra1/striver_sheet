class Solution {
  public:
    string preToInfix(string pre_exp)
    {
        string ans=" ";
        stack<string> st;
        
        for(int i=pre_exp.length()-1 ; i>=0 ; i--)
        {
           char ch=pre_exp[i];
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
               string con = "(" + t1 +ch + t2 + ")";
               st.push(con);
           }
        }
        return st.top();
        
        
        
    }
};
