/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return vector<vector<int>>();
        }
        vector<vector<int>> ans;

        queue<TreeNode *> nodeQ;
        queue<int> levelQ;
        nodeQ.push(root);
        levelQ.push(0);

        while (!nodeQ.empty())
        {
            auto curNode = nodeQ.front();
            nodeQ.pop();
            int curLevel = levelQ.front();
            levelQ.pop();

            if (ans.size() < curLevel + 1)
            {
                vector<int> v;
                ans.push_back(v);
            }
            ans[curLevel].push_back(curNode->val);

            if (curNode->left != nullptr)
            {
                nodeQ.push(curNode->left);
                levelQ.push(curLevel + 1);
            }
            if (curNode->right != nullptr)
            {
                nodeQ.push(curNode->right);
                levelQ.push(curLevel + 1);
            }
        }

        return ans;
    }
};