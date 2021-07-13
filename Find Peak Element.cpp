class Solution {
public:
    
    int sol(vector<int>& nums, int low, int high)
    {
        int mid = low + (high - low) / 2;   // Getting mid of array

        // We return mid when:
          // 1. mid is at 0-th index OR prev_num less than mid
          // AND
          // 2. mid is at n-th index OR next_num less than mid
        if( (mid == 0 || nums[mid-1] < nums[mid]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]) )
            return mid;

        // Go for the right half of array when
          // 1. mid is less than size of array
          // AND
          // 2. No. at mid is less than next_num
        if( mid < nums.size() - 1 && nums[mid] < nums[mid+1] )
            return sol(nums, mid + 1, high);

        // AT END, GO FOR LEFT HALF OF ARRAY
        return sol(nums, low, mid);
    }
    
    int findPeakElement(vector<int>& nums)
    {
        return sol(nums, 0, nums.size());
    }
};
