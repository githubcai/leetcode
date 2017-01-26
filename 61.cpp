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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int hlen = 0;
        ListNode *first = head, *second = head;
        while(first != NULL) hlen += 1, first = first->next;
        k %= hlen;
        if(k == 0) return head;
        first = head;
        for(int i = 0; i < k; ++i) first = first->next;
        while(first->next != NULL) first = first->next, second = second->next;
        first->next = head;
        head = second->next;
        second->next = NULL;
        return head;
    }
};
