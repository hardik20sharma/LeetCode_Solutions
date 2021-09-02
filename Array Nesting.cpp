class Solution {
public:
    int arrayNesting(vector<int> &nums)
    {
        int n = nums.size(), res = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
            if (!visited[i])
            {
                int start = nums[i], cnt = 0;
                do
                {
                    cnt++;
                    visited[start] = true;
                    
                    start = nums[start];
                } while (start != nums[i]);

                res = max(res, cnt);
            }

        return res;
    }
};
