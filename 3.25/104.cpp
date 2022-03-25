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
    int traverse(TreeNode* node)
    {
        int level=0;
        if(node->left!=nullptr)
        {
            int n=this->traverse(node->left);
            level=(level>n)?level:n;
        }

        if(node->right!=nullptr)
        {
            int n=this->traverse(node->right);
            level=(level>n)?level:n;
        }

        return level+1;
    }
    int maxDepth(TreeNode* root) {
        if(root!=nullptr)
        {
            return traverse(root);
        }
        return 0;
    }
};