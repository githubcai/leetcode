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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        int ret;
        que.push(root);
        while(!que.empty()){
            TreeNode *now = que.front();
            ret = now->val;
            int size = que.size();
            while(size-- > 0){
                now = que.front();
                que.pop();
                if(now->left != NULL) que.push(now->left);
                if(now->right != NULL) que.push(now->right);
            }
        }
        return ret;
    }
};
