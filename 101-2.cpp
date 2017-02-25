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
        stack<TreeNode*> stk;
        while(lRoot != NULL && rRoot != NULL){
            if(lRoot->val != rRoot->val) return false;
            stk.push(lRoot);
            stk.push(rRoot);
            lRoot = lRoot->left;
            rRoot = rRoot->right;
        }
        if((lRoot == NULL && rRoot != NULL) || (lRoot != NULL && rRoot == NULL)) return false;
        while(!stk.empty()){
            rRoot = stk.top(); stk.pop();
            lRoot = stk.top(); stk.pop();
            lRoot = lRoot->right;
            rRoot = rRoot->left;
            while(lRoot != NULL && rRoot != NULL){
                if(lRoot->val != rRoot->val) return false;
                stk.push(lRoot);
                stk.push(rRoot);
                lRoot = lRoot->left;
                rRoot = rRoot->right;   
            }
            if((lRoot == NULL && rRoot != NULL) || (lRoot != NULL && rRoot == NULL)) return false;
        }
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
