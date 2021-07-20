class Solution {
    vector<int> og_array;
    vector<int> shuffle_array;
    
public:
    Solution(vector<int>& nums)
    {
        for(int i : nums)
        {
            og_array.push_back(i);
            shuffle_array.push_back(i);
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return og_array;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        int i = rand() % og_array.size();
        int j = rand() % og_array.size();
        
        swap(shuffle_array[i], shuffle_array[j]);
        
        return shuffle_array;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
