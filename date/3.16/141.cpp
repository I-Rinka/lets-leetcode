/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        auto cur1 = head;
        auto cur2 = head;
        while (cur1 != nullptr && cur2 != nullptr)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
            if (cur2 == nullptr)
            {
                break;
            }
            cur2 = cur2->next;
            if (cur2 == cur1)
            {
                return true;
            }
        }
        return false;
    }
};