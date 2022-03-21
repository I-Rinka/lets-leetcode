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
    void reorderList(ListNode* head) {
        stack<ListNode*>stk;
        auto cur=head;

        if(head==nullptr)
        {
            return;
        }
        while(cur!=nullptr)
        {
            stk.push(cur);
            cur=cur->next;
        }

        cur=head;
        ListNode* in;
        int sz=stk.size();
        while(true)
        {
            in=stk.top();
            stk.pop();

            if(cur==in)
            {
                cur->next=nullptr;
                return;
            }
            if(cur->next==in)
            {
                in->next=nullptr;
                return;
            }

            in->next=cur->next;
            cur->next=in;

            cur=in->next;
        }

        
    }
};