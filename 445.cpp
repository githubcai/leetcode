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
        stack<int> stk1, stk2;
        while(l1 != NULL){
            stk1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            stk2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *ret = NULL;
        int c = 0;
        while(!stk1.empty() && !stk2.empty()){
            int temp = stk1.top() + stk2.top() + c;
            stk1.pop(); stk2.pop();
            c = temp / 10;
            temp %= 10;
            ListNode *node = new ListNode(temp);
            node->next = ret;
            ret = node;
        }
        while(!stk1.empty()){
            int temp = stk1.top() + c;
            stk1.pop();
            c = temp / 10;
            temp %= 10;
            ListNode *node = new ListNode(temp);
            node->next = ret;
            ret = node;
        }
        while(!stk2.empty()){
            int temp = stk2.top() + c;
            stk2.pop();
            c = temp / 10;
            temp %= 10;
            ListNode *node = new ListNode(temp);
            node->next = ret;
            ret = node;
        }
        if(c != 0){
            ListNode *node = new ListNode(c);
            node->next = ret;
            ret = node;
        }
        return ret;
    }
};
