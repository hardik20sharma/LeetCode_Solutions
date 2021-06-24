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
    int totalSum = 0;
public:

    void sol(TreeNode *root, int num = 0)
    {
        
        if (root == NULL)
            return;
        
        num += root->val;
        
        if (root->left == NULL && root->right == NULL)
        {
            totalSum += num;
            return;
        }
        
        sol(root->left, num * 10);
        sol(root->right, num * 10);
    }

    int sumNumbers(TreeNode *root)
    {
        sol(root);
        return totalSum;
    }
};
