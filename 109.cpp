/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* build(vector<int> nums, int left, int right){
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head != NULL){
            nums.push_back(head->val);
            head = head->next;
        }
        TreeNode *root = build(nums, 0, nums.size() - 1);
        return root;
    }
};
