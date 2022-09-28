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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)
        {
            return ans;
        }
        queue<TreeNode*> nodeQ;
        queue<int> levelQ;
        nodeQ.push(root);
        levelQ.push(0);

        while(!nodeQ.empty())
        {
            auto curNode=nodeQ.front();
            nodeQ.pop();
            int curLevel=levelQ.front();
            levelQ.pop();

            if(ans.size()<curLevel+1)
            {
                ans.push_back(vector<int>());
            }
            if(curLevel%2==0)
            {
                ans[curLevel].push_back(curNode->val);
            }
            else
            {
                ans[curLevel].insert(ans[curLevel].begin(),curNode->val);
            }

            if(curNode->left!=nullptr)
            {
                nodeQ.push(curNode->left);
                levelQ.push(curLevel+1);
            }
            if(curNode->right!=nullptr)
            {
                nodeQ.push(curNode->right);
                levelQ.push(curLevel+1);
            }
        }

        return ans;
    }
};