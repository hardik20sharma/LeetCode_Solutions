class Solution {
public:
    
    int binarySearchEndPos(vector<int> nums, int low, int high, int target)
    {
        if(high < low)
            return -1;

        int mid = low + (high - low)/2;

        if ((mid == nums.size() - 1 || target < nums[mid+1]) && nums[mid] == target)
            return mid;
        else if (target < nums[mid])
            return binarySearchEndPos(nums, low, mid-1, target);
        else
            return binarySearchEndPos(nums, mid+1, high, target);
    }
    
    
    int binarySearchStartPos(vector<int> nums, int low, int high, int target)
    {
        if(high < low)
            return -1;

        int mid = low + (high-low)/2;

        if ( (mid == 0 || target > nums[mid-1]) && nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            return binarySearchStartPos(nums, mid+1, high, target);
        else
            return binarySearchStartPos(nums, low, mid-1, target);
    }
    

    vector<int> searchRange(vector<int>& nums, int target)
    {   
        vector<int> res;
        res.push_back(binarySearchStartPos(nums, 0, nums.size()-1, target));
        res.push_back(binarySearchEndPos(nums, 0, nums.size()-1, target));
        return res;
    }
};
