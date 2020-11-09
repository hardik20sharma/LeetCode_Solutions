class Solution {
public:
    int thirdMax(vector<int>& nums)
    {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        bool int_min_exists = false;    // Checks if the array has INT_MIN as element or not
        for(int num : nums)
        {
            if(num == INT_MIN)
                int_min_exists = true;  // If array has INT_MIN as element, make it true.
            
            if(num == max1 || num == max2 || num <= max3)
                continue;

            if(num > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if(num > max2)
            {
                max3 = max2;
                max2 = num;
            }
            else
                max3 = num;
        }

        // If max3 is INT_MIN and array doesn't contain INT_MIN as element, print max1
        // If max2 is INT_MIN and array does contain INT_MIN, print max1
        
        if ( (max3 == INT_MIN && !int_min_exists) || max2 == INT_MIN)
            return max1;
        else
            return max3;
    }
};
