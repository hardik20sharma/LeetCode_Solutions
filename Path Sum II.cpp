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

    void sol(TreeNode* root, vector<int>& path, vector<vector<int>> &res, int &target, int sum = 0)
    {
        if(root == NULL)
            return;

        sum += root->val;   // Adding current value in sum
        path.push_back(root->val);  // include the path

        if(!root->left && !root->right && sum == target)    // Reached leaf and target matches
            res.push_back(path);

        sol(root->left, path, res, target, sum);    // explore left
        sol(root->right, path, res, target, sum);   // explore right

        path.pop_back();    // exclude the path
    }

public:

    vector<vector<int>> pathSum(TreeNode* root, int target)
    {
        if(root == NULL)
            return {};

        vector<vector<int>> res;
        vector<int> path;

        sol(root, path, res, target);

        return res;
    }
};
