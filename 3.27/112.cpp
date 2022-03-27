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
    bool ans=false;
    void findHeight(TreeNode*node,int now_sum,int targetSum)
    {
        if(now_sum+node->val==targetSum&&node->left==nullptr&&node->right==nullptr)
        {
            this->ans=true;
            return;
        }
        
        if(!this->ans&&node->left!=nullptr)
        {
            this->findHeight(node->left,now_sum+node->val,targetSum);
        }

        if(!this->ans&&node->right!=nullptr)
        {
            this->findHeight(node->right,now_sum+node->val,targetSum);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
        {
            return false;
        }
        this->findHeight(root,0,targetSum);
        return this->ans;
    }
};