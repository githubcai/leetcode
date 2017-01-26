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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while(root != NULL){
            stk.push(root);
            root = root->left;
        }
        int cnt = 0;
        while(!stk.empty()){
            root = stk.top();
            stk.pop();
            cnt += 1;
            if(k == cnt) return root->val;
            root = root->right;
            while(root != NULL){
                stk.push(root);
                root = root->left;
            }
        }
        return -1;
    }
};
