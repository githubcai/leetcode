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
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        int temp1 = 0, temp2 = root->val;
        if(root->left != NULL){
            temp1 += rob(root->left);
            if(root->left->left != NULL) temp2 += rob(root->left->left);
            if(root->left->right != NULL) temp2 += rob(root->left->right);
        }
        if(root->right != NULL){
            temp1 += rob(root->right);
            if(root->right->left != NULL) temp2 += rob(root->right->left);
            if(root->right->right != NULL) temp2 += rob(root->right->right);
        }
        return max(temp1, temp2);
        
    }
};
