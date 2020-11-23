class Solution {
private:
    int dp[110][110];
public:
    
    int sol(vector<int> &a, int curr, int last)
    {
        if(dp[curr][last] != -1)
            return dp[curr][last];

        if(curr == 0)
            if(last == curr+1)
                return dp[curr][last] = 0;
            else
                return dp[curr][last] = a[curr];

        if(curr == last-1)
            return dp[curr][last] = sol(a, curr-1, last);

        return dp[curr][last] = max(a[curr] + sol(a, curr-1, curr), sol(a, curr-1, last) );
    }

    int rob(vector<int>& nums)
    {
        if(nums.size() == 0)
            return 0;
        else if(nums.size() == 1)
            return nums[0];
        memset(dp, -1, sizeof(dp));
        return sol(nums, nums.size()-1, 108);
    }
};
