/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* mergeTwoLists(ListNode* l1, ListNode *l2){
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *ret, *temp;
        if(l1->val <= l2->val){
            ret = temp = l1;
            l1 = l1->next;
        }else{
            ret = temp = l2;
            l2 = l2->next;
        }
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }else{
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        if(l1 != NULL){
            temp->next = l1;
        }else if(l2 != NULL){
            temp->next = l2;
        }
        return ret;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.size() == 0) return NULL;
        vector<ListNode*> ret;
        copy(lists.begin(), lists.end(), back_inserter(ret));
        while(ret.size() > 1){
            vector<ListNode*> temp;
            int i;
            for(i = 0; i + 1 < ret.size(); i += 2){
                temp.push_back(mergeTwoLists(ret[i], ret[i + 1]));
            }
            if(i < ret.size()) temp.push_back(ret[i]);
            ret.clear();
            copy(temp.begin(), temp.end(), back_inserter(ret));
        }
        return ret[0];
    }
};
