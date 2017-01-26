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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *fHead = new ListNode(0);
        ListNode *first = fHead, *second = fHead;
        first->next = head;
        while(first->next != NULL){
            if(first->next->val >= x) break;
            first = first->next;
        }
        if(first->next == NULL){
            delete fHead;
            return head;
        }
        second = first->next;
        while(second->next != NULL){
            if(second->next->val < x){
                ListNode *temp = second->next;
                second->next = second->next->next;
                temp->next = first->next;
                first->next = temp;
                first = first->next;
            }else{
                second = second->next;
            }
        }
        head = fHead->next;
        delete fHead;
        return head;
    }
};
