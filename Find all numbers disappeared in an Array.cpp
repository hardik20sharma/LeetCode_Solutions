class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        for(int i=0; i<nums.size(); i++)
        {
            int temp = abs(nums[i]) - 1;
            if(0 < nums[temp])
                nums[temp] = -nums[temp];
        }

        vector<int> res;
        for(int i=0; i<nums.size(); i++)
            if(0 < nums[i])
                res.push_back(i+1);
        
        return res;
    }
};
