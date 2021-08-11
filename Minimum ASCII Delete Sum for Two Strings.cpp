class Solution
{

    vector<vector<int>> dp;

    int sol(string &s1, string &s2, int i, int j)
    {
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i == 0)
        {
            int sum = 0;
            for(int k = 0; k < j; k++)
                sum += s2[k];
            return dp[i][j] = sum;
        }

        if(j == 0)
        {
            int sum = 0;
            for(int k = 0; k < i; k++)
                sum += s1[k];
            return dp[i][j] = sum;
        }

        if(s1[i-1] == s2[j-1])
            return dp[i][j] = sol(s1, s2, i-1, j-1);

        int ans1 = s1[i-1] + sol(s1, s2, i-1, j);
        int ans2 = s2[j-1] + sol(s1, s2, i, j-1);
        
        return dp[i][j] = min(ans1, ans2);
    }

public:
    int minimumDeleteSum(string word1, string word2)
    {
        dp.resize( word1.size() + 1, vector<int>(word2.size() + 1, -1) );
        return sol(word1, word2, word1.size(), word2.size());
    }
};
