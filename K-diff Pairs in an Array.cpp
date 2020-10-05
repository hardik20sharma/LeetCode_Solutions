class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        set<int> s;
        int res = 0;
        
        if(k == 0)
        {
            set<int> set_k0;
            for(int i=0; i<nums.size(); i++)
            {
                if( s.find(nums[i]) != s.end() && set_k0.find(nums[i]) == set_k0.end() )
                {
                    res++;
                    set_k0.insert(nums[i]);
                }
                s.insert(nums[i]);
            }
        }
        
        else
            for(int i=0; i<nums.size(); i++)
            {
                if( s.find(nums[i] - k) != s.end() && s.find(nums[i]) == s.end() )
                    res++;
                
                if( s.find(nums[i] + k) != s.end() && s.find(nums[i]) == s.end() )
                    res++;
                
                s.insert(nums[i]);
            }

        return res;
    }
};
