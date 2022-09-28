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
    vector<int> inorderTraversal(TreeNode* root) {
        queue<TreeNode*>stk;
        vector<int>ans;
        if(root==nullptr)
        {
            return ans;
        }
        else
        {
            this->traverse(root,ans);
        }
        return ans;
    }
    void traverse(TreeNode*node,vector<int>&ans)
    {
        if(node->left!=nullptr)
        {
            this->traverse(node->left,ans);
        }
        ans.push_back(node->val);
        if(node->right!=nullptr)
        {
            this->traverse(node->right,ans);
        }
    }
};