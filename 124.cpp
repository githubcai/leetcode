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
    int getMax(TreeNode* root, int &ans){
        if(root == NULL) return 0;
        int ret = root->val;
        int tLeft = getMax(root->left, ans);
        if(tLeft > 0) ret += tLeft;
        int tRight = getMax(root->right, ans);
        if(tRight > 0) ret += tRight;
        if(ans < ret) ans = ret;
        int temp = (tLeft > tRight ? tLeft : tRight);
        if(temp < 0) temp = 0;
        return root->val + temp;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = INT_MIN;
        getMax(root, ans);
        return ans;
    }
};
