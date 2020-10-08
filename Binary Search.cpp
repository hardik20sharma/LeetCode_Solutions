class Solution {
public:
    
    int binarySearch(vector<int> a, int low, int high, int target)
    {
        if(high < low)
            return - 1;
        
        int mid = low + (high-low)/2;
        
        if (target == a[mid])
            return mid;
        
        else if(target < a[mid])
            return binarySearch(a, low, mid-1, target);
        
        else
            return binarySearch(a, mid+1, high, target);
        
    }
    
    int search(vector<int>& nums, int target)
    {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
};
