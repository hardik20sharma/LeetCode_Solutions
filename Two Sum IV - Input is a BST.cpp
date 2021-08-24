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

// We try the brute force approach, for each node we search for its complement

class Solution {

  
    // We use two nodes root and curr. Motive behind using two pointers is to make sure we don't count current pointer again.
    // Example: sum is 10 and we have one node as 5. We don't want to count 5 twice.

    bool ifContains(TreeNode *root, TreeNode *curr, int n)  // Function to find the complement
    {
        if(root == NULL)
            return false;

        if(root != curr && root->val == n)
            return true;

        if(root->val < n)
            return ifContains(root->right, curr, n);

        return ifContains(root->left, curr, n);
    }

    // We use two nodes root and curr
    bool traverse(TreeNode *root, TreeNode *curr, int sum)  // Traversing the nodes individually
    {
        if(root == NULL || curr == NULL)
            return false;

        bool ans1 = ifContains(root, curr, sum - curr->val);
        if(ans1)
            return true;

        bool ans2 = traverse(root, curr->left, sum);        
        if(ans2)
            return true;
        
        bool ans3 = traverse(root, curr->right, sum);
        if(ans3)
            return true;

        return false;
    }

public:
    bool findTarget(TreeNode* root, int sum)  // Solution
    {
        if(root == NULL)
            return false;

        return traverse(root, root, sum);
    }
};
