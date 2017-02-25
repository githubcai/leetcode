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
    TreeNode* build(const vector<int> &nums, int left, int right){
        if(left > right) return NULL;
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        if(left == right) return root;
        TreeNode *temp = build(nums, left, mid - 1);
        root->left = temp;
        temp = build(nums, mid + 1, right);
        root->right = temp;
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        TreeNode *root = build(nums, 0, nums.size() - 1);
        return root;
    }
};
