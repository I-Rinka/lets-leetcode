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
    bool traverse(TreeNode*l,TreeNode*r)
    {
        if(l==nullptr&&r==nullptr)
        {
            return true;
        }
        else if(l==nullptr)
        {
            return false;
        }
        else if(r==nullptr)
        {
            return false;
        }
        
        // not null
        if(l->val!=r->val)
        {
            return false;
        }
        bool ans1=this->traverse(l->right,r->left);
        if(!ans1)
        {
            return false;
        }
        bool ans2=this->traverse(l->left,r->right);

        return ans1&&ans2;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
        {
            return true;
        }
        return this->traverse(root->left,root->right);
    }
};