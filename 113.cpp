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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if(root == NULL) return ret;
        if(root->left == NULL && root->right == NULL){
            if(root->val == sum){
                vector<int> temp;
                temp.push_back(root->val);
                ret.push_back(temp);
            }
            return ret;
        }
        if(root->left != NULL){
            vector<vector<int>> tret = pathSum(root->left, sum - root->val);
            if(tret.size() != 0){
                for(int i = 0; i < tret.size(); ++i){
                    vector<int> temp;
                    temp.push_back(root->val);
                    for(int j = 0; j < tret[i].size(); ++j){
                        temp.push_back(tret[i][j]);
                    }
                    ret.push_back(temp);
                }
            }
        }
        if(root->right != NULL){
            vector<vector<int>> tret = pathSum(root->right, sum - root->val);
            if(tret.size() != 0){
                for(int i = 0; i < tret.size(); ++i){
                    vector<int> temp;
                    temp.push_back(root->val);
                    for(int j = 0; j < tret[i].size(); ++j){
                        temp.push_back(tret[i][j]);
                    }
                    ret.push_back(temp);
                }
            }
        }
        return ret;
    }
};
