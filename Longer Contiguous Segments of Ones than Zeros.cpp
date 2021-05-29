class Solution {
public:

    int sol(string s, char c)
    {
        int n = s.length(), res;

        vector<int> dp (n, 0);

        dp[0] = (s[0] == c) ? 1 : 0;
        res = dp[0];

        for(int i = 1; i < n; res = max(res, dp[i]), i++)
            if(s[i] == c)
                dp[i] = 1 + dp[i-1];
            else
                dp[i] = 0;

        return res;
    }
    
    bool checkZeroOnes(string s)
    {
        int cnt1 = sol(s, '1'), cnt2 = sol(s, '0');
        return cnt1 > cnt2;
    }
};
