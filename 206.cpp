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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *first = head->next, *temp = head;
        while(first != NULL){
            ListNode *t = first->next;
            first->next = temp;
            temp = first;
            first = t;
        }
        head->next = NULL;
        head = temp;
        return head;
    }
};
