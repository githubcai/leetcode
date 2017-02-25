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
    unordered_map<int, int> ref;
    
    int dfs(TreeNode *root){
        if(root == NULL) return 0;
        int sum = root->val;
        if(root->left != NULL) sum += dfs(root->left);
        if(root->right != NULL) sum += dfs(root->right);
        ref[sum] += 1;
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        ref.clear();
        dfs(root);
        vector<int> ret;
        int mx = -1;
        for(auto iter = ref.begin(); iter != ref.end(); ++iter){
            if(iter->second > mx){
                ret.clear();
                mx = iter->second;
                ret.push_back(iter->first);
            }else if(iter->second == mx){
                ret.push_back(iter->first);
            }
        }
        return ret;
    }
};
