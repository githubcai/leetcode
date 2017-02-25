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
    TreeNode* build(const vector<int> &preorder, const vector<int> &inorder, int pl, int pr, int il, int ir){
        if(pl > pr) return NULL;
        TreeNode *root = new TreeNode(preorder[pl]);
        if(pl == pr) return root;
        int ind;
        for(ind = il; ind <= ir; ++ind){
            if(preorder[pl] == inorder[ind]) break;
        }
        TreeNode *temp = build(preorder, inorder, pl + 1, pl + ind - il, il, ind - 1);
        root->left = temp;
        temp = build(preorder, inorder, pl + ind - il + 1, pr, ind + 1, ir);
        root->right = temp;
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
        return root;
        
    }
};
