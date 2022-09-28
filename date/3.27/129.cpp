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

    int curSum=0;
    void traverse(TreeNode*node,int curValue)
    {
        int nowValue=curValue*10+node->val;
        if(node->left==nullptr&&node->right==nullptr)
        {
            curSum+=nowValue;
        }
        else
        {
            if(node->left!=nullptr)
            {
                this->traverse(node->left,nowValue);
            }
            if(node->right!=nullptr)
            {
                this->traverse(node->right,nowValue);
            }
        }

    }
    int sumNumbers(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        this->traverse(root,0);
        return this->curSum;
    }
};