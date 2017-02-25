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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int aSize = 0, bSize = 0;
        ListNode *aTemp = headA, *bTemp = headB, *aLast = NULL, *bLast = NULL;
        while(aTemp != NULL){
            aSize += 1;
            aLast = aTemp;
            aTemp = aTemp->next;
        }
        while(bTemp != NULL){
            bSize += 1;
            bLast = bTemp;
            bTemp = bTemp->next;
        }
        if(aLast != bLast) return NULL;
        if(aSize > bSize){
            int temp = aSize - bSize;
            while(temp > 0){
                headA = headA->next;
                temp -= 1;
            }
        }else{
            int temp = bSize - aSize;
            while(temp > 0){
                headB = headB->next;
                temp -= 1;
            }
        }
        while(headB != headA && aSize > 0){
            headB = headB->next;
            headA = headA->next;
        }
        return headA;
    }
};
