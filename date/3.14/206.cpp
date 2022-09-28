class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }

        if (head->next == NULL)
        {
            return head;
        }

        stack<ListNode *> nodeStack;
        for (auto i = head; i != nullptr; i = i->next)
        {
            nodeStack.push(i);
        }
        auto ans = nodeStack.top();
        auto currentNode = nodeStack.top();
        nodeStack.pop();
        while (!nodeStack.empty())
        {
            auto current = nodeStack.top();
            nodeStack.pop();
            currentNode->next = current;
            currentNode = current;
            current->next = NULL;
        }
        return ans;
    }
};