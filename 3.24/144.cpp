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
    void traverse(TreeNode*node,vector<int>&vec)
    {
        vec.push_back(node->val);
        if(node->left!=nullptr)
        {
            this->traverse(node->left,vec);
        }

        if(node->right!=nullptr)
        {
            this->traverse(node->right,vec);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root!=nullptr)
        {
            this->traverse(root,ans);
        }
        return ans;
    }
};