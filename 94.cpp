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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ret;
        if(root == NULL) return ret;
        TreeNode *temp = root;
        while(temp != NULL){
            stk.push(temp);
            temp = temp->left;
        }
        while(!stk.empty()){
            temp = stk.top();
            stk.pop();
            ret.push_back(temp->val);
            temp = temp->right;
            while(temp != NULL){
                stk.push(temp);
                temp = temp->left;
            }
        }
        return ret;
    }
};
