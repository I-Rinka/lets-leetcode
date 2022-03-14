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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        else if (list2 == nullptr)
            return list1;

        auto cur1 = list1, cur2 = list2;
        ListNode *ans = nullptr;
        if (cur1->val > cur2->val)
        {
            ans = cur2;
            cur2 = cur2->next;
        }
        else
        {
            ans = cur1;
            cur1 = cur1->next;
        }
        auto cur = ans;
        while (cur1 != nullptr || cur2 != nullptr)
        {
            // next node is cur2
            if (cur1 == nullptr || cur2 != nullptr && cur1->val > cur2->val)
            {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            else
            {
                cur->next = cur1;
                cur1 = cur1->next;
            }
            cur = cur->next;
        }
        return ans;
    }
};