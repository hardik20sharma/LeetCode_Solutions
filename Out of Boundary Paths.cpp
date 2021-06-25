class Solution {
    int mod = 1000000007;
public:

    int sol(int &m, int &n, int maxMove, int i, int j, vector<vector<vector<int>>> &dp)
    {   
        if(i == m || j == n || i < 0 || j < 0)
            return 1;

        if(maxMove == 0)
            return dp[i][j][maxMove] = 0;

        if(dp[i][j][maxMove] >= 0)
            return dp[i][j][maxMove];

        return dp[i][j][maxMove] = 
            (
                (sol(m, n, maxMove - 1, i-1, j, dp) + sol(m, n, maxMove - 1, i+1, j, dp)) % mod

                +

                (sol(m, n, maxMove - 1, i, j-1, dp) + sol(m, n, maxMove - 1, i, j+1, dp)) % mod            
            ) % mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startCol)
    {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));

        return sol(m, n, maxMove, startRow, startCol, dp);
    }
};
