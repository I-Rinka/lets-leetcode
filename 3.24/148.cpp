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
    struct cmp{
        bool operator() (ListNode* a,ListNode* b)
        {
            return a->val>b->val;
        }
    };
    ListNode* sortList(ListNode* head) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>q;
        if(head==nullptr)
        {
            return head;
        }
        auto cur=head;
        while(cur!=nullptr)
        {
            q.push(cur);
            cur=cur->next;
        }

        auto n_head=q.top();
        q.pop();
        cur=n_head;
        while(!q.empty())
        {
            cur->next=q.top();
            q.pop();
            cur=cur->next;
            cur->next=nullptr;
        }
        return n_head;
    }
};