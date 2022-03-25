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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
        {
            return l2;
        }
        else if(l2==nullptr)
        {
            return l1;
        }

        ListNode*header=new ListNode();
        int l=l1->val;
        int r=l2->val;
        int carry=0;

        auto cur=header;

        while(l1!=nullptr||l2!=nullptr)
        {
            cur->next=new ListNode();
            cur=cur->next;
            if(l1==nullptr)
            {
                l=0;
            }
            else
            {
                l=l1->val;
                l1=l1->next;
            }
            
            if(l2==nullptr)
            {
                r=0;
            }
            else
            {
                r=l2->val;
                l2=l2->next;
            }
            
            cur->val=(l+r+carry)%10;
            carry=(l+r+carry)/10;
            cur->next=nullptr;
            
        }
        if(carry!=0)
        {
            cur->next=new ListNode();
            cur=cur->next;
            cur->val=carry;
            cur->next=nullptr;
        }
        return header->next;
    }
};