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
private:
    unordered_map<TreeNode*, int> dp;
public:
    int rob(TreeNode* root)
    {
        if(dp.find(root) != dp.end())
            return dp[root];

        if(root == NULL)
           return 0;

        int temp = 0;
        if(root->left != NULL)
            temp += rob(root->left->left) + rob(root->left->right);
        if(root->right != NULL)
            temp += rob(root->right->left) + rob(root->right->right);

        return dp[root] = max( root->val + temp, rob(root->left) + rob(root->right) );
    }
};
