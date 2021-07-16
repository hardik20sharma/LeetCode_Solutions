class Solution {
public:
    
    int binary_search(vector<int> &nums, int low, int high, int n)
    {
        if(high < low)  // 
            return -1;

        int mid = low + (high - low) / 2;   // Getting the mid of array

        if(nums[mid] == n)    // If n is present in mid, return mid
            return mid;

        if(nums[low] <= nums[mid])    // If nums[low] is less than nums[mid] .... ensuring we have 4, 5, 6, 7 and not 7, 4, 5, 6 [NOTE: EXAMPLE ARRAY]
        {
            if(nums[low] <= n && n < nums[mid])             // If low <= n < mid, search in this part of array itself
                return binary_search(nums, low, mid-1, n);
            else
                return binary_search(nums, mid+1, high, n);   // else we search in right half of array
        }
        else                                              // If nums[low] > nums[mid], we understand array is of the form 7, 4, 5, 6.
        {
            if(nums[mid] < n && n <= nums[high])            // If mid < n <= high, we search in this part of array itself
                return binary_search(nums, mid+1, high, n);
            else
                return binary_search(nums, low, mid-1, n);  // else we search in left half of array.
        }
    }
    
    int search(vector<int>& nums, int target)
    {
        return binary_search(nums, 0, nums.size() - 1, target);
    }
};
