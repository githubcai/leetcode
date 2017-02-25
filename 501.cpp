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
    void search(TreeNode *root, unordered_map<int, int> &ref){
        if(root->left != NULL) search(root->left, ref);
        if(root->right != NULL) search(root->right, ref);
        ref[root->val] += 1;
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ret;
        if(root == NULL) return ret;
        unordered_map<int, int> ref;
        search(root, ref);
        int mx = INT_MIN;
        for(auto iter : ref){
            if(iter.second > mx) mx = iter.second;
        }
        for(auto iter : ref){
            if(iter.second == mx) ret.push_back(iter.first);
        }
        return ret;
    }
};
