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
    TreeNode* build(const vector<int> &inorder, vector<int> &postorder, int il, int ir, int pl, int pr){
        if(il > ir) return NULL;
        TreeNode *root = new TreeNode(postorder[pr]);
        int ind;
        for(ind = il; ind <= ir; ++ind){
            if(inorder[ind] == postorder[pr]) break;
        }
        TreeNode *temp = build(inorder, postorder, il, ind - 1, pl, pl + ind - il - 1);
        root->left = temp;
        temp = build(inorder, postorder, ind + 1, ir, pl + ind - il, pr - 1);
        root->right = temp;
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
        return root;
    }
};
