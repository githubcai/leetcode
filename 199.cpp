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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            ret.push_back(que.front()->val);
            int size = que.size();
            for(int i = 0; i < size; ++i){
                TreeNode *now = que.front();
                que.pop();
                if(now->right != NULL) que.push(now->right);
                if(now->left != NULL) que.push(now->left);
            }
        }
        return ret;
    }
};
