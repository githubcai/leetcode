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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *fHead = new ListNode(0);
        fHead->next = head;
        ListNode *first = fHead, *second = head;
        for(int i = m; i < n; ++i){
            if(second == NULL){
                delete fHead;
                return head;
            }
            second = second->next;
        }
        for(int i = 1; i < m; ++i){
            if(second == NULL){
                delete fHead;
                return head;
            }
            first = first->next;
            second = second->next;
        }
        ListNode *tFirst = first;
        ListNode *temp = second->next;
        first = first->next;
        while(first != second){
            ListNode *t = first->next;
            first->next = temp;
            temp = first;
            first = t;
        }
        second->next = temp;
        tFirst->next = second;
        head = fHead->next;
        delete fHead;
        return head;
    }
};
