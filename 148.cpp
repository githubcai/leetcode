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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        int size = 0;
        ListNode *first = head, *second;
        while(first != NULL){
            size += 1;
            first = first->next;
        }
        size /= 2;
        first = head;
        for(int i = 1; i < size; ++i) first = first->next;
        second = first->next;
        first->next = NULL;
        first = head;
        first = sortList(first);
        second = sortList(second);
        ListNode *ret, *temp;
        if(first->val > second->val){
            ret = second;
            second = second->next;
        }else{
            ret = first;
            first = first->next;
        }
        temp = ret;
        while(first != NULL && second != NULL){
            if(first->val < second->val){
                temp->next = first;
                first = first->next;
            }else{
                temp->next = second;
                second = second->next;
            }
            temp = temp->next;
        }
        if(first != NULL) temp->next = first;
        if(second != NULL) temp->next = second;
        return ret;
    }
};
