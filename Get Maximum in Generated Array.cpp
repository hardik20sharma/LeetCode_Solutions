class Solution {
public:
    int getMaximumGenerated(int n)
    {
        if(n == 0)
            return 0;

        vector<int> nums(n+1);

        nums[0] = 0;
        nums[1] = 1;

        int res = 1;
        for(int i=2; i<=n; i++)
        {
            if(i % 2)
            {
                int j = (i - 1) / 2;
                nums[i] = nums[j] + nums[j+1];
            }

            else
            {
                int j = i/2;
                nums[i] = nums[j];
            }

            res = max(res, nums[i]);
        }
        
        return res;
    }
};
