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
    bool check(TreeNode *lRoot, TreeNode *rRoot){
        if(lRoot->val != rRoot->val) return false;
        if((lRoot->left == NULL && rRoot->right != NULL) || (lRoot->left != NULL && rRoot->right == NULL)) return false;
        if(lRoot->left != NULL && rRoot->right != NULL && !check(lRoot->left, rRoot->right)) return false;
        if((lRoot->right == NULL && rRoot->left != NULL) || (lRoot->right != NULL && rRoot->left == NULL)) return false;
        if(lRoot->right != NULL && rRoot->left != NULL && !check(lRoot->right, rRoot->left)) return false;
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left != NULL && root->right != NULL) return check(root->left, root->right);
        if(root->left == root->right && root->left == NULL) return true;
        return false;
    }
};
