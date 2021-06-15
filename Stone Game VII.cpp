class Solution {
    
    vector<vector<int>> dp;
    
public:
    
    int sol(vector<int> &stones, int l, int r, int sum)
    {   
        if(l == r)
            return 0;

        if(r - l == 1)
            return max(stones[l], stones[r]);
        
        if(dp[l][r] != -1)
            return dp[l][r];
        
        return dp[l][r] = max(
            sum - stones[l] - sol(stones, l+1, r, sum - stones[l]) ,
            sum - stones[r] - sol(stones, l, r-1, sum - stones[r]) );
    }

    int stoneGameVII(vector<int>& stones)
    {
        dp.clear();
        dp.resize(stones.size(), vector<int>(stones.size(), -1));

        int sum = 0;
        for(int s : stones)
            sum += s;
        
        return sol(stones, 0, stones.size() - 1, sum);
    }
};
