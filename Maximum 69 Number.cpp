class Solution {
public:
    int maximum69Number (int num)
    {
        stack<int> st;

        while(num)
        {
            st.push(num % 10);
            num /= 10;
        }

        num = 0;
        bool switched = false;

        while(!st.empty())
        {
            if(!switched && st.top() == 6)
            {
                num = (num * 10) + 9;
                switched = true;
            }
            else
                num = (num * 10) + st.top();
            st.pop();
        }

        return num;
    }
};
