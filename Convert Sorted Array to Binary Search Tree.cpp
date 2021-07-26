/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    TreeNode *sol(vector<int> &nums, int start, int end)
    {
        if(end < start)
            return NULL;

        int mid = start + (end - start)/2;

        return new TreeNode(nums[mid], sol(nums, start, mid-1), sol(nums, mid+1, end));
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return sol(nums, 0, nums.size()-1);
    }
};
