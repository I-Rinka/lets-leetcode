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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        auto cur1=head;
        auto cur2=head;
        for(int i=0;i<k;i++)
        {
            if(cur1==NULL)
            {
                return NULL;
            }
            cur1=cur1->next;
        }

        while(cur1!=NULL)
        {
            cur1=cur1->next;
            cur2=cur2->next;
        }
        return cur2;
    }
};