/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int size = 0;
        ListNode *temp = head;
        while(temp != NULL){
            size += 1;
            temp = temp->next;
        }
        ListNode *left = head, *right;
        temp = NULL;
        int lmt = size / 2;
        for(int i = 0; i < lmt; ++i){
            ListNode *t = left->next;
            left->next = temp;
            temp = left;
            left = t;
        }
        if(size % 2 == 1){
            right = left->next;
        }else{
            right = left;
        }
        ListNode *mid = left;
        left = temp;
        while(left != NULL){
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        left = temp; temp = mid;
        while(left != NULL){
            ListNode *t = left->next;
            left->next = temp;
            temp = left;
            left = t;
        }
        return true;
    }
};
