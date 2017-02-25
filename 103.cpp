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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> que;
        bool flag = false;
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
            if(flag){
                reverse(temp.begin(), temp.end());
            }
            flag = !flag;
            ret.push_back(temp);
        }
        return ret;
    }
};
