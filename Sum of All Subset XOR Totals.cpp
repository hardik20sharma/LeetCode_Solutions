class Solution {
public:
    int subsetXORSum(vector<int>& nums)
    {    
        int bits = 0;

        for (int i=0; i < nums.size(); i++)
            bits |= nums[i];

        return bits * pow(2, nums.size() - 1);
    }
};
