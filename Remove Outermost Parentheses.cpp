class Solution {
public:
    string removeOuterParentheses(string s)
    {
        stack<char> st;

        string res = "";


        for(int i=0; i<s.length(); i++)        
            if(s[i] == '(')
            {
                st.push('(');

                if(st.size() >= 2)
                    res += '(';
            }

            else
            {
                if(st.size() >= 2)
                    res += ')';

                st.pop();
            }
        
        return res;
    }
};
