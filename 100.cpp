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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;
        if(p != NULL && p->val != q->val) return false;
        if(p != NULL){
            if((p->left == NULL && q->left != NULL) || (p->left != NULL && q->left == NULL)) return false;
            if(p->left != NULL && !isSameTree(p->left, q->left)) return false; ;
            if((p->right == NULL && q->right != NULL) || (p->right != NULL && q->right == NULL)) return false;
            if(q->right != NULL && !isSameTree(p->right, q->right)) return false;;
        }
        return true;
    }
};
