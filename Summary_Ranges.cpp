class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 0)
            return vector<string>();
        if(n == 1)
            return vector<string> {to_string(nums[0])};

        vector<string> result;

        for(int i=0; i<n-1; i++)
            if(nums[i] == nums[i+1] - 1)
            {
                int j = i;
                while(j < n-1 && nums[j] == nums[j+1] - 1)
                    j++;
                result.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
                i = j;
            }
            else
                result.push_back(to_string(nums[i]));

        if(nums[n-2] != nums[n-1] - 1)
            result.push_back(to_string(nums[n-1]));

        return result;
    }
};
