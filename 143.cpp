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
    void reorderList(ListNode* head) {
        int size = 0;
        ListNode *first = head, *second;
        while(first != NULL){
            first = first->next;
            size += 1;
        }
        if(size < 3) return;
        size = size / 2 + size % 2;
        first = head;
        while(size > 1){
            first = first->next;
            size -= 1;
        }
        second = first->next;
        first->next = NULL;
        first = second;
        second = second->next;
        first->next = NULL;
        while(second != NULL){
            ListNode *temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }
        second = first;
        first = head;
        while(second != NULL){
            ListNode *temp = first->next;
            first->next = second;
            second = second->next;
            first->next->next = temp;
            first = first->next->next;
        }
    }
};
