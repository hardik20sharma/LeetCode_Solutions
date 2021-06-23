class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        
        int res = 0, min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        
        for(int i : nums)
        {
            if(max1 < i)
            {
                max3 = max2;
                max2 = max1;
                max1 = i;
            }

            else if(max2 < i)
            {
                max3 = max2;
                max2 = i;
            }

            else if(max3 < i)
                max3 = i;

            if(min1 > i)
            {
                min2 = min1;
                min1 = i;
            }
            else if(min2 > i)
                min2 = i;
        }

        return max(max1 * max2 * max3, min1 * min2 * max1);
        
    }
};
