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
    int cnt;
    TreeNode *store[2][2], *pre;
    
    void getNode(TreeNode *node){
        if(cnt > 1) return;
        if(node->left != NULL) getNode(node->left);
        if(pre != NULL && node->val < pre->val){
            store[cnt][0] = pre;
            store[cnt][1] = node;
            cnt += 1;
        }
        pre = node;
        if(node->right != NULL) getNode(node->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        if(root == NULL) return;
        cnt = 0; pre = NULL;
        getNode(root);
        if(cnt == 2){
            int temp = store[0][0]->val;
            store[0][0]->val = store[1][1]->val;
            store[1][1]->val = temp;
        }else if(cnt == 1){
            int temp = store[0][0]->val;
            store[0][0]->val = store[0][1]->val;
            store[0][1]->val = temp;
        }
    }
};
