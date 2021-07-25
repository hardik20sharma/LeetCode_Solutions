class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        if(nums.size() == 1)
            return true;
        
        int max_dist = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            max_dist = max(max_dist, i + nums[i]);
            
            if(max_dist >= nums.size() - 1)
                return true;
            
            if(i == max_dist)
                return false;
        }
        
        return false;
    }
};
