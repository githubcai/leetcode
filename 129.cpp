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
    void getSum(TreeNode *root, int num, int &ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            ans += num * 10 + root->val;
            return;
        }
        if(root->left != NULL) getSum(root->left, num * 10 + root->val, ans);
        if(root->right != NULL) getSum(root->right, num * 10 + root->val, ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        getSum(root, 0, ans);
        return ans;
    }
};
