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
    
    unordered_map<TreeNode*, int> dp;
    
    int height(TreeNode *root)
    {
        if(root == NULL)
            return dp[root] = 0;
        
        if(dp[root])
            return dp[root];

        return dp[root] = 1 + max(height(root->left), height(root->right));
    }
    
public:
    bool isBalanced(TreeNode* root)
    {   
        if(root == NULL)
            return true;

        if( abs(height(root->left) - height(root->right)) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);

        return false;
    }
};
