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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> temp;
            for(int i = 0; i < size; ++i){
                TreeNode *now = que.front();
                que.pop();
                temp.push_back(now->val);
                if(now->left != NULL) que.push(now->left);
                if(now->right != NULL) que.push(now->right);
            }
            ret.push_back(temp);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
