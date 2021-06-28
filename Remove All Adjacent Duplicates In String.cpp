class Solution {
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        
        for(int i = s.length() - 1; 0 <= i; i--)
        {
            while(!st.empty() && 0 <= i && st.top() == s[i])
            {
                st.pop();
                i--;
            }
            
            if(0 <= i)
                st.push(s[i]);
        }

        
        string res;
        while(st.empty() == false)
        {
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};
