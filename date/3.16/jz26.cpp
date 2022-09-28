/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (A == nullptr || B == nullptr)
        {
            return false;
        }
        queue<TreeNode *> buf;
        buf.push(A);
        while (!buf.empty())
        {
            auto now_node = buf.front();
            buf.pop();
            if (now_node->val == B->val)
            {
                if (isEqualTree(now_node, B))
                {
                    return true;
                }
            }
            if (now_node->left != nullptr)
            {
                buf.push(now_node->left);
            }
            if (now_node->right != nullptr)
            {
                buf.push(now_node->right);
            }
        }
        return false;
    }

    bool isEqualTree(TreeNode *srcRoot, TreeNode *dstRoot)
    {
        stack<TreeNode *> tdS;
        stack<TreeNode *> tsS;
        tsS.push(srcRoot);
        tdS.push(dstRoot);

        while (!tdS.empty())
        {
            TreeNode *NS = tsS.top();
            tsS.pop();
            TreeNode *ND = tdS.top();
            tdS.pop();

            if (ND->left != nullptr)
            {
                if (NS->left == nullptr || NS->left->val != ND->left->val)
                {
                    return false;
                }
                else
                {
                    tsS.push(NS->left);
                    tdS.push(ND->left);
                }
            }
            if (ND->right != nullptr)
            {
                if (NS->right == nullptr || NS->right->val != ND->right->val)
                {
                    return false;
                }
                else
                {
                    tsS.push(NS->right);
                    tdS.push(ND->right);
                }
            }
        }
        return true;
    }
};