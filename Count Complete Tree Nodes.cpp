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


/* --- Trivial Sollution --- */

class Solution {
public:
    int countNodes(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        return 1 + countNodes(root->left) + countNode(root->right);
    }
};


/* --- Optimized Solution --- */

class Solution {
public:
    int countNodes(TreeNode* root)
    {
        int left_height = 0, right_height = 0;
        
        TreeNode *left = root, *right = root;
        
        while(left != NULL)
        {
            left_height++;
            left = left->left;
        }

        while(right != NULL)
        {
            right_height++;
            right = right->right;
        }

        if(left_height == right_height)
            return pow(2, left_height) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
