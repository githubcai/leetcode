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
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left != NULL && !isValidBST(root->left)) return false;
        if(root->right != NULL && !isValidBST(root->right)) return false;
        if(root->left != NULL){
            TreeNode *temp = root->left;
            while(temp->right != NULL) temp = temp->right;
            if(temp->val >= root->val) return false;
        }
        if(root->right != NULL){
            TreeNode *temp = root->right;
            while(temp->left != NULL) temp = temp->left;
            if(temp->val <= root->val) return false;
        }
        return true;
    }
};
