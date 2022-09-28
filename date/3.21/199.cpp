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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr)
        {
            return ans;
        }
        set<int>visit;
        queue<TreeNode*>nodeQ;
        queue<int>levelQ;

        nodeQ.push(root);
        levelQ.push(0);

        while(!nodeQ.empty())
        {
            auto curNode=nodeQ.front();
            auto curLevel=levelQ.front();
            nodeQ.pop();
            levelQ.pop();

            if(visit.find(curLevel)==visit.end())
            {
                visit.insert(curLevel);
                ans.push_back(curNode->val);
            }

            if(curNode->right!=nullptr)
            {
                nodeQ.push(curNode->right);
                levelQ.push(curLevel+1);
            }

            if(curNode->left!=nullptr)
            {
                nodeQ.push(curNode->left);
                levelQ.push(curLevel+1);
            }
        }
        return ans;
    }
};