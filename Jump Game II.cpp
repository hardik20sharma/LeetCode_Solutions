class Solution {
public:
    int jump(vector<int>& nums)
    {   
        if(nums.size() == 1 || nums[0] == 0)
            return 0;

        int jumps = 1, farthest = nums[0], curr_end = nums[0];
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == nums.size() - 1)
                return jumps;

            farthest = max(farthest, i + nums[i]);

            if(i == curr_end)
            {
                jumps++;
                curr_end = farthest;
            }
        }
        
        return jumps;
    }
};
