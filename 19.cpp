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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head, *second = head;
        for(int i = 0; i < n; ++i) first = first->next;
        if(first == NULL){
            head = second->next;
            delete second;
        }else{
            while(first->next != NULL){
                first = first->next;
                second = second->next;
            }
            ListNode *temp = second->next;
            second->next = temp->next;
            delete temp;
        }
        return head;
    }
};
