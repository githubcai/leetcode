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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        if(k <= 0) return head;
        ListNode *first = head, *second = head, *pre = NULL;
        for(int i = 1; i < k; ++i){
            if(second->next == NULL) return head;
            second = second->next;
        }
        head = second;
        while(second != NULL){
            if(pre != NULL) pre->next = second;
            pre = first;
            while(first != second){
                ListNode *temp = first->next;
                first->next = second->next;
                second->next = first;
                first = temp;
            }
            second = first = pre->next;
            if(first == NULL) return head;
            for(int i = 1; i < k; ++i){
                if(second->next == NULL) return head;
                second = second->next;
            }
        }
        return head;
    }
};
