class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int res = INT_MAX;

        for(int i = 0, j = 0, sum = 0; j < nums.size(); j++)
        {
            sum += nums[j];

            while (target <= sum)
            {
                res = min(res, j - i + 1);
                sum -= nums[ i++ ];
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};
