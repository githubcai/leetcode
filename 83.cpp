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
        ListNode *now = head;
        while(now != NULL && now->next != NULL){
            if(now->val == now->next->val){
                ListNode *temp = now->next;
                now->next = now->next->next;
                delete temp;
            }else{
                now = now->next;
            }
        }
        return head;
    }
};
