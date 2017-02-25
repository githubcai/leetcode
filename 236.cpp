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
    bool flag;
    
    void getPath(TreeNode *p, TreeNode *node, vector<TreeNode*> &vec){
        if(p == NULL || flag) return;
        if(p == node){
            flag = true;
            return;
        }
        if(p->left != NULL && !flag){
            vec.push_back(p->left);
            getPath(p->left, node, vec);
            if(!flag) vec.pop_back();
        }
        if(p->right != NULL && !flag){
            vec.push_back(p->right);
            getPath(p->right, node, vec);
            if(!flag) vec.pop_back();
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == NULL || q == NULL) return NULL;
        vector<TreeNode*> pVec, qVec;
        flag = false;
        pVec.push_back(root);
        getPath(root, p, pVec);
        flag = false;
        qVec.push_back(root);
        getPath(root, q, qVec);
        TreeNode *ret = root;
        for(int i = 1, j = 1; i < pVec.size() && j < qVec.size(); ++i, ++j){
            if(pVec[i] != qVec[j]) break;
            ret = pVec[i];
        }
        return ret;
    }
};
