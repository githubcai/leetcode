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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root == NULL) return ret;
        stack<TreeNode*> stk;
        TreeNode *temp = root;
        while(temp != NULL){
            stk.push(temp);
            stk.push(temp);
            temp = temp->left;
        }
        while(!stk.empty()){
            temp = stk.top();
            stk.pop();
            if(!stk.empty() && temp == stk.top()){
                temp = temp->right;
                while(temp != NULL){
                    stk.push(temp);
                    stk.push(temp);
                    temp = temp->left;
                }
            }else{
                ret.push_back(temp->val);
            }
        }
        return ret;
    }
};
