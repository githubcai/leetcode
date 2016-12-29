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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = NULL, *last = NULL, *node;
        int temp = 0;
        while(l1 && l2){
            temp = l1->val + l2->val + temp;
            node = new ListNode(temp  % 10);
            if(last == NULL){
                ret = last = node;
            }else{
                node->next = last->next;
                last->next = node;
                last = node;
            }
            temp = temp / 10;
            l1 = l1->next, l2 = l2->next;
        }
        if(l1){
            while(l1){
                temp = temp + l1->val;
                node = new ListNode(temp % 10);
                node->next = last->next;
                last->next = node;
                last = node;
                temp = temp / 10;
                l1 = l1->next;
            }
        }else if(l2){
            while(l2){
                temp = temp + l2->val;
                node = new ListNode(temp % 10);
                node->next = last->next;
                last->next = node;
                last = node;
                temp = temp / 10;
                l2 = l2->next;
            }
        }
        if(temp != 0){
            node = new ListNode(temp);
            node->next = last->next;
            last->next = node;
            last = node;
        }
        return ret;
    }
};
