/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur1=head;
        ListNode* cur2=head;

        for(int i=0;i<n;i++)
        {
            if(cur1==nullptr)
            {
                return nullptr;
            }
            cur1=cur1->next;
        }

        if(cur1==nullptr)
        {
            return head->next;
        }

        while(cur1->next!=nullptr)
        {
            cur1=cur1->next;
            cur2=cur2->next;
        }

        cur2->next=cur2->next->next;
        return head;
    }
};