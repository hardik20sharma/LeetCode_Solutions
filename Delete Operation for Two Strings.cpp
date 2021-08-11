class Solution {

    vector<vector<int>> dp;

    int sol(string &s1, string &s2, int i, int j)
    {
        if(i == 0)
            return j;

        if(j == 0)
            return i;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i-1] == s2[j-1])
            return dp[i][j] = sol(s1, s2, i-1, j-1);

        return dp[i][j] = 1 + min( sol(s1, s2, i-1, j), sol(s1, s2, i, j-1) );
    }

public:
    int minDistance(string word1, string word2)
    {
        dp.resize( word1.size() + 1, vector<int>(word2.size() + 1, -1) );
        return sol(word1, word2, word1.size(), word2.size());
    }
};
