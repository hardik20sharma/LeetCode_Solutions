class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k)
    {
        vector<int> index;
        
        for(int i=0; i < nums.size(); i++)
            if(nums[i] == 1)
                index.push_back(i);
        
        for(int i=1; i < index.size(); i++)
            if(index[i] - index[i-1] <= k)
                return false;
        
        return true;
    }
};
