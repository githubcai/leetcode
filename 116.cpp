/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        root->next = NULL;
        while(root->left != NULL){
            TreeLinkNode *pre = root, *cur = root->left;
            while(pre != NULL){
                if(pre->right != NULL){
                    cur->next = pre->right;
                    cur = cur->next;
                    pre = pre->next;
                    if(pre != NULL){
                        cur->next = pre->left;
                        cur = cur->next;
                    }else{
                        cur->next = NULL;
                    }
                }else{
                    cur->next = NULL;
                }
            }
            root = root->left;
        }
    }
};
