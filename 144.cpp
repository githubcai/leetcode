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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root == NULL) return ret;
        stack<TreeNode*> stk;
        TreeNode *temp = root;
        while(temp != NULL){
            ret.push_back(temp->val);
            if(temp->right != NULL) stk.push(temp->right);
            temp = temp->left;
        }
        while(!stk.empty()){
            temp = stk.top();
            stk.pop();
            while(temp != NULL){
                ret.push_back(temp->val);
                if(temp->right != NULL) stk.push(temp->right);
                temp = temp->left;
            }
        }
        return ret;
    }
};
