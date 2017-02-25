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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *ret = head;
        head = head->next;
        ret->next =NULL;
        while(head != NULL){
            ListNode *temp = ret;
            if(head->val < temp->val){
                ListNode *t = head->next;
                head->next = temp;
                ret = head;
                head = t;
            }else{
                while(temp->next != NULL){
                    if(temp->next->val >= head->val){
                        ListNode *t = head->next;
                        head->next = temp->next;
                        temp->next = head;
                        head = t;
                        break;
                    }
                    temp = temp->next;
                }
                if(temp->next == NULL){
                    ListNode *t = head->next;
                    head->next = temp->next;
                    temp->next = head;
                    head = t;
                }
            }
        }
        return ret;
    }
};
