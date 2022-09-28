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
    ListNode* deleteDuplicates(ListNode* head) {
        multiset<int>visit;

        auto cur1=head;
        while(cur1!=nullptr)
        {
            visit.insert(cur1->val);
            cur1=cur1->next;
        }

        cur1=head;
        while(cur1!=nullptr&&visit.count(cur1->val)>1)
        {
            cur1=cur1->next;
        }
        head=cur1;
        if(cur1==nullptr)
        {
            return nullptr;
        }
        auto cur2=cur1->next;

        for(auto k:visit)
        {
            cout<<k<<" "<<visit.count(k)<<endl;
        }
        while(cur2!=nullptr)
        {
            if(visit.count(cur2->val)>1)
            {
                while(cur2!=nullptr&&visit.count(cur2->val)>1)
                {
                    cur2=cur2->next;
                }
                cur1->next=cur2;
                if(cur2==nullptr)
                {
                    break;
                }
            }

            cur1=cur1->next;
            cur2=cur2->next;
        }
        return head;
    }
};