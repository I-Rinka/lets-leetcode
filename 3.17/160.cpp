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
        auto curA=headA;
        auto curB=headB;

        bool r1=true;
        bool r2=true;

        while(curA!=NULL&&curB!=NULL)
        {
            if(curA==curB)
            {
                return curA;
            }
            
            if(curA->next==NULL&&r1)
            {
                curA=headB;
                r1=false;
            }
            else
            {
                curA=curA->next;
            }
            if(curB->next==NULL&&r2)
            {
                curB=headA;
                r2=false;
            }
            else
            {
                curB=curB->next;
            }
        }
        return NULL;
    }
};