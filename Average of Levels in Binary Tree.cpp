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
public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> res;
        
        queue<TreeNode*> q;
        
        if(root != NULL)
            q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            double sum = 0;
            
            for(int i = 0; i < n; i++)
            {
                root = q.front();
                q.pop();

                sum += root->val;

                if(root->left != NULL)
                    q.push(root->left);
                if(root->right != NULL)
                    q.push(root->right);
            }
            
            res.push_back( (double) sum / (double) n );
        }
        
        return res;
    }
};
