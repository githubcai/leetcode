/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int dfs(TreeNode *root){
        int lDepth = 0, rDepth = 0;
        if(root->left != NULL) lDepth = dfs(root->left);
        if(root->right != NULL) rDepth = dfs(root->right);
        if(lDepth == -1 || rDepth == -1) return -1;
        if(lDepth - rDepth > 1 || rDepth - lDepth > 1) return -1;
        return (lDepth > rDepth ? lDepth : rDepth) + 1;
    }
    
public:
    bool isBalanced(TreeNode* root){
        if(root == NULL) return true;
        int ret = dfs(root);
        if(ret == -1) return false;
        return true;
    }
};
