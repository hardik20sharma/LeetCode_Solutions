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
class Solution
{
    int cnt;

    void sol(TreeNode* root, int curr_max = INT_MIN)
    {
        if(root == NULL)
            return;

        if(root->val >= curr_max)
            cnt++;

        sol(root->left, max(root->val, curr_max) );
        sol(root->right, max(root->val, curr_max) );
    }

public:
    int goodNodes(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        cnt = 0;

        sol(root);

        return cnt;
    }
};
