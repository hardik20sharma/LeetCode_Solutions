class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;    // Resulting vector
        stack<TreeNode*> s;   // Stack, for iterative approach

        for(TreeNode *curr = root; curr != NULL || !s.empty(); )    // Using a curr pointer, loop runs till curr pointer isn't null and isn't empty
        {
            while(curr != NULL)     // Traversing and storing all left side
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            res.push_back(curr->val);   // Add the result in vector
            curr = curr->right;
        }

        return res;
    }
};
