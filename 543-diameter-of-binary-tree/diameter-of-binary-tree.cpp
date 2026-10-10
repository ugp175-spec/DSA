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

    int func(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        return 1 + max(func(root->left),func(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {

        if(root == NULL)
        {
            return 0;
        }

        int lh = func(root->left);
        int rh = func(root->right);

        int curr = lh + rh;

        return max(curr,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));

        
        
    }
};