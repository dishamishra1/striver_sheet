#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int priority(char c) 
    {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }

    string infixToPostfix(string s)
    {
        stack<char> st;
        string ans = "";

        for(int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if((ch >= 'a' && ch <= 'z') ||
               (ch >= 'A' && ch <= 'Z') ||
               (ch >= '0' && ch <= '9'))
            {
                ans += ch;
            }
            else if(ch == '(')
            {
                st.push(ch);
            }
            else if(ch == ')')
            {
                while(!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            else
            {
                while(!st.empty() && 
                     (priority(ch) < priority(st.top()) || 
                     (priority(ch) == priority(st.top()) && ch == '^')))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }

    string infixToPrefix(string s)
    {
        // 1. Reverse
        reverse(s.begin(), s.end());

        // 2. Swap brackets
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(') s[i] = ')';
            else if(s[i] == ')') s[i] = '(';
        }

        // 3. Infix → Postfix
        string postfix = infixToPostfix(s);

        // 4. Reverse result
        reverse(postfix.begin(), postfix.end());

        return postfix;
    }
};
