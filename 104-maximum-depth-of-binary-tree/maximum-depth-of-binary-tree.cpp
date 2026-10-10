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

    void  func(TreeNode* root,int &ans,int &depth)
    {
        if(root == NULL)
        {
            ans = max(ans,depth);
            return;
        }

        depth++;
        func(root->left,ans,depth);

        func(root->right,ans,depth);
        depth--;
    }
    int maxDepth(TreeNode* root) {

        int ans = 0;
        int depth = 0;
        func(root,ans,depth);
        return ans;
        
    }
};