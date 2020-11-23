class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& a)
    {
        int m = a.size(), n = a[0].size();

        if(a[0][0] || a[m-1][n-1])
            return 0;

        int dp[m][n];
        for(int i=0, temp = 1; i<m; i++)      // Base condition
        {
            if(a[i][0])
                temp = 0;
            dp[i][0] = temp;
        }

        for(int j=0, temp = 1; j<n; j++)      // Base condition
        {
            if(a[0][j])
                temp = 0;
            dp[0][j] = temp;
        }

        for(int i=1; i<m; i++)      // Calculation
            for(int j=1; j<n; j++)
                if(a[i][j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];

        return dp[m-1][n-1];
    }
};
