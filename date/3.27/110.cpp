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
    int ans=true;
    int curHeight(TreeNode* node)
    {
        int l=0;
        int r=0;
        if(this->ans)
        {
            if(node->left!=nullptr)
            {
                l=this->curHeight(node->left);
            }

            if(node->right!=nullptr)
            {
                r=this->curHeight(node->right);
            }

            if(l-r>1||r-l>1)
            {
                this->ans=false;
            }

            return (l>r)?l+1:r+1;
        }
        return 0;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
        {
            return true;
        }
        this->curHeight(root);
        return this->ans;
    }
};