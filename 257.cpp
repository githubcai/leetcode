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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(root == NULL) return ret;
        if(root->left == NULL && root->right == NULL){
            stringstream ss;
            ss << root->val;
            string temp;
            ss >> temp;
            ret.push_back(temp);
            return ret;
        }
        if(root->left != NULL){
            vector<string> tret = binaryTreePaths(root->left);
            for(int i = 0; i < tret.size(); ++i){
                stringstream ss;
                ss << root->val;
                string temp;
                ss >> temp;
                temp += "->";
                temp += tret[i];
                ret.push_back(temp);
            }
        }
        if(root->right != NULL){
            vector<string> tret = binaryTreePaths(root->right);
            for(int i = 0; i < tret.size(); ++i){
                stringstream ss;
                ss << root->val;
                string temp;
                ss >> temp;
                temp += "->";
                temp += tret[i];
                ret.push_back(temp);
            }
        }
        return ret;
    }
};
