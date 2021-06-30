class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int i = 0, j = 0, subarray_zeros = 0, res = INT_MIN;
        
        while(j < nums.size())
        {
            if(nums[j] == 1)
                j++;

            else if(nums[j] == 0)
            {
                j++;
                subarray_zeros++;
            }

            while(k < subarray_zeros)
            {
                if(nums[i] == 0)
                    subarray_zeros--;
                i++;
            }

            res = max(res, j - i);
        }

        return res;
    }
};
