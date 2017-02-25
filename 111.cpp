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
    int minDepth(TreeNode* root) {
        int ret = 0;
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            ret += 1;
            for(int i = 0; i < size; ++i){
                TreeNode *now = que.front();
                que.pop();
                if(now->left == NULL && now->right == NULL) return ret;
                if(now->left != NULL) que.push(now->left);
                if(now->right != NULL) que.push(now->right);
            }
        }
        return ret;
    }
};
