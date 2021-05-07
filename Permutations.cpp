class Solution {
    
    vector< vector<int> > result;
    
public:
    
    void sol(vector<int> nums, int low, int high)
    {
        if(low == high)
            result.push_back(nums);

        for(int i = low; i < high; i++)
        {
            swap(nums[low], nums[i]);
            sol(nums, low + 1, high);
            swap(nums[low], nums[i]);
        }
    }

    vector< vector<int> > permute(vector<int>& nums)
    {
        sol(nums, 0, nums.size());
        return result;
    }
};
