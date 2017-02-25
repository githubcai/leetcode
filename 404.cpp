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
    int dfs(TreeNode *root, TreeNode *pre){
        int ret = 0;
        if(root == NULL) return ret;
        if(root->left != NULL) ret += dfs(root->left, root);
        if(root->right != NULL) ret += dfs(root->right, root);
        if(root->left == NULL && root->right == NULL && pre != NULL && pre->left == root) ret = root->val;
        return ret;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, NULL);
    }
};
