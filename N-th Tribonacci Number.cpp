class Solution {
public:
    int tribonacci(int n)
    {
        if(n == 0)
            return 0;
        
        if(n == 1 || n == 2)
            return 1;
        
        int dp[n+1];

        dp[0] = 0; dp[1] = 1; dp[2] = 1;

        for(int i = 3; i <= n; i++)
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];

        return dp[n];
    }
};

/*
    Tn+3 = Tn + Tn+1 + Tn+2  
    Tn = Tn-3 + Tn-2 + Tn-1
*/
