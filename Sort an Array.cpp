class Solution {
public:
    
    void merge(vector<int>& nums, int low, int mid, int high)
    {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        vector<int> left(n1), right(n2);

        for (int i = 0; i < n1; i++)
            left[i] = nums[ low + i ];

        for (int j = 0; j < n2; j++)
            right[j] = nums[ (mid + 1) + j ];

        int curr_left = 0, curr_right = 0, curr_main = low;

        while(curr_left < n1 && curr_right < n2)
            if(left[curr_left] < right[curr_right])
                nums[curr_main++] = left[curr_left++];
            else
                nums[curr_main++] = right[curr_right++];

        while(curr_left < n1)
            nums[curr_main++] = left[curr_left++];

        while(curr_right < n2)
            nums[curr_main++] = right[curr_right++];
    }

    void mergeSort(vector<int>&nums, int low, int high)
    {
        if(high <= low)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);

        merge(nums, low, mid, high);
    }
    
    vector<int> sortArray(vector<int>& nums)
    {
        int low = 0, high = nums.size() - 1;

        mergeSort(nums, low, high);

        return nums;
    }
};
