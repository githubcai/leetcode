/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *ret = NULL, *tHead = head;
        if(tHead == NULL) return ret;
        while(tHead != NULL){
            RandomListNode *temp = new RandomListNode(tHead->label);
            temp->next = tHead->next;
            tHead->next = temp;
            tHead = temp->next;
        }
        ret = head->next;
        tHead = head;
        while(tHead != NULL){
            if(tHead->random != NULL){
                tHead->next->random = tHead->random->next;
                tHead = tHead->next->next;
            }else{
                tHead->next->random = NULL;
                tHead = tHead->next->next;
            }
        }
        tHead = head;
        while(tHead != NULL){
            RandomListNode *temp = tHead->next;
            tHead->next = tHead->next->next;
            if(temp->next != NULL){
                temp->next = temp->next->next;
            }else{
                temp->next = NULL;
            }
            tHead = tHead->next;
        }
        return ret;
    }
};
