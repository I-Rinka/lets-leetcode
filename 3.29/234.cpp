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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
        {
            return true;
        }
        auto sCur=head;
        auto fCur=head;
        bool isOdd=true;
        while(true)
        {
            if(fCur->next==nullptr)
            {
                break;
            }
            sCur=sCur->next;
            fCur=fCur->next;
            fCur=fCur->next;
            if(fCur==nullptr)
            {
                isOdd=false;
                break;
            }
        }

        // turn over
        auto cur=head;
        ListNode* p=nullptr;
        while(cur!=sCur)
        {
            auto t=cur->next;
            cur->next=p;
            p=cur;
            cur=t;
        }
        auto cu1=p;
        auto cu2=cur;

        if(isOdd)
        {
            cu2=cu2->next;
        }

        bool ans=true;
        while(true)
        {
            if(cu1==nullptr&&cu2==nullptr)
            {
                break;
            }
            else if(cu1==nullptr)
            {
                ans=false;
                break;
            }
            else if(cu2==nullptr)
            {
                ans=false;
                break;
            }
            if(cu2->val!=cu1->val)
            {
                ans=false;
                break;
            }
            cu1=cu1->next;
            cu2=cu2->next;
        }

        // recover

        return ans;
    }
};