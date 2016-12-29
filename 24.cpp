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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *first = head, *second = head->next, *pre = NULL;
        if(second == NULL) return head;
        head = second;
        while(second != NULL){
            first->next = second->next;
            second->next = first;
            if(pre != NULL) pre->next = second;
            pre = first;
            first = first->next;
            if(first == NULL) break;
            second = first->next;
        }
        return head;
    }
};
