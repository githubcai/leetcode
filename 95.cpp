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
    vector<int> dp;
    
    vector<TreeNode*> build(int left, int right){
        vector<TreeNode*> ret;
        if(left == right){
            TreeNode *temp = new TreeNode(left);
            ret.push_back(temp);
            return ret;
        }
        for(int i = left; i <= right; ++i){
            if(i == left){
                vector<TreeNode*> tRet = build(i + 1, right);
                for(int j = 0; j < tRet.size(); ++j){
                    TreeNode *temp = new TreeNode(i);
                    temp->left = NULL;
                    temp->right = tRet[j];
                    ret.push_back(temp);
                }
            }else if(i == right){
                vector<TreeNode*> tRet = build(left, i - 1);
                for(int j = 0; j < tRet.size(); ++j){
                    TreeNode *temp = new TreeNode(i);
                    temp->right = NULL;
                    temp->left = tRet[j];
                    ret.push_back(temp);
                }
            }else{
                vector<TreeNode*> tRet;
                vector<vector<TreeNode*>> lStore, rStore;
                for(int j = 0; j < dp[right - i]; ++j){
                    tRet = build(left, i - 1);
                    lStore.push_back(tRet);
                }
                for(int j = 0; j < dp[i - left]; ++j){
                    tRet = build(i + 1, right);
                    rStore.push_back(tRet);
                }
                for(int j = 0; j < dp[i - left]; ++j){
                    for(int k = 0; k < dp[right - i]; ++k){
                        TreeNode *temp = new TreeNode(i);
                        temp->left = lStore[k][j];
                        temp->right = rStore[j][k];
                        ret.push_back(temp);
                    }
                }
            }
        }
        return ret;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if(n < 1) return ret;
        dp.resize(n + 1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = 0;
            for(int j = 0; j < i; ++j){
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        ret = build(1, n);
        return ret;
    }
};
