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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if(root == NULL) return ret;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode *now = que.front();
            int size = que.size(), temp = now->val;
            while(size-- > 0){
                now = que.front();
                que.pop();
                if(temp < now->val) temp = now->val;
                if(now->left != NULL) que.push(now->left);
                if(now->right != NULL) que.push(now->right);
            }
            ret.push_back(temp);
        }
        return ret;
    }
};
