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
        while(root != NULL){
            TreeLinkNode *pre = root, *cur = NULL;
            while(pre != NULL){
                if(pre->left != NULL){
                    root = cur = pre->left;
                    if(pre->right != NULL){
                        cur->next = pre->right;
                        cur = cur->next;
                    }
                    break;
                }
                if(pre->right != NULL){
                    root = cur = pre->right;
                    break;
                }
                pre = pre->next;
            }
            if(pre != NULL){
                pre = pre->next;
            }else{
                break;
            }
            while(pre != NULL){
                if(pre->left != NULL){
                    cur->next = pre->left;
                    cur = cur->next;
                }
                if(pre->right != NULL){
                    cur->next = pre->right;
                    cur = cur->next;
                }
                pre = pre->next;
            }
            if(cur != NULL) cur->next = NULL;
        }
    }
};
