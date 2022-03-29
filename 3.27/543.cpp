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
    priority_queue<int>PQ;
    int longest(TreeNode* node)
    {
        if(node==nullptr)
        {
            return 0;
        }
        int l=0;
        int r=0;
        if(node->left!=nullptr)
        {
            l=this->longest(node->left);
        }

        if(node->right!=nullptr)
        {
            r=this->longest(node->right);
        }

        int ans=(l>r)?l:r;
        this->PQ.push(l+r);
        return ans+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        this->longest(root);
        return this->PQ.top();
    }
};