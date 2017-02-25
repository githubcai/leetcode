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
    int dfs(TreeNode *root, int total, int sum){
        int ret = 0;
        if(total == sum) ret += 1;
        if(root->left != NULL) ret += dfs(root->left, total + root->left->val, sum);
        if(root->right != NULL) ret += dfs(root->right, total + root->right->val, sum);
        return ret;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        int ret = 0;
        if(root == NULL) return ret;
        if(root->left != NULL) ret += pathSum(root->left, sum);
        if(root->right != NULL) ret += pathSum(root->right, sum);
        ret += dfs(root, root->val, sum);
        return ret;
    }
};
