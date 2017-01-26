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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        while(head != NULL && head->next != NULL && head->val == head->next->val){
            int temp = head->val;
            while(head != NULL && head->val == temp){
                ListNode *tNode = head;
                head = head->next;
                delete tNode;
            }
        }
        if(head == NULL) return head;
        ListNode *pre = head, *now = head->next;
        while(now != NULL){
            if(now->next != NULL && now->val == now->next->val){
                int temp = now->val;
                while(now != NULL && now->val == temp){
                    ListNode *tNode = now;
                    now = now->next;
                    pre->next = now;
                    delete tNode;
                }
            }else{
                pre = now;
                now = now->next;
            }
        }
        return head;
    }
};
