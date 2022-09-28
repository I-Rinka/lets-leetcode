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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int i = 0;
        ListNode *start = head;
        ListNode *ans = head;
        ListNode *preNode = nullptr;
        bool fst = true;
        for (ListNode *node = head; node != nullptr; node = node->next)
        {
            if ((i + 1) % k == 0)
            {
                if (fst)
                {
                    ans = node;
                    fst = false;
                }
                if (preNode != nullptr)
                {
                    preNode->next = node;
                }
                node = swapNodes(start, k);
                preNode = node;
                start = node->next;
            }
            i++;
        }
        return ans;
    }
    ListNode *swapNodes(ListNode *start, int k)
    {
        ListNode *fin = start;
        ListNode *sn = start->next;
        for (int i = 0; i < k - 1; i++)
        {
            fin->next = sn->next;
            sn->next = start;
            start = sn;
            sn = fin->next;
        }
        return fin;
    }
};