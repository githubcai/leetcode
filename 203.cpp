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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val){
            ListNode *temp = head->next;
            delete head;
            head = temp;
        }
        if(head == NULL) return NULL;
        ListNode *now = head, *pre = NULL;
        while(now != NULL){
            if(now->val == val){
                if(pre != NULL) pre->next = now->next;
                ListNode *temp = now->next;
                delete now;
                now = temp;
            }else{
                pre = now;
                now = now->next;
            }
        }
        return head;
    }
};
