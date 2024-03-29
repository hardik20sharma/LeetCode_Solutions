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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> res;
        
        queue<TreeNode*> q;
        
        if(root)
            q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            vector<int> sub_res;
            
            for(int i = 0; i < n; i++)
            {
                root = q.front();
                q.pop();

                sub_res.push_back(root->val);
                
                if(root->left)
                    q.push(root->left);

                if(root->right)
                    q.push(root->right);
            }
            
            res.push_back(sub_res);
        }
        
        return vector(res.rbegin(), res.rend());
    }
};
