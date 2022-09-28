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
    int maxPathSum(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }

        priority_queue<int>ans;
        this->fuckMyBack(root,ans);
        
        return ans.top();
    }
    int fuckMyBack(TreeNode*node,priority_queue<int>&a)
    {
        a.push(node->val);
        int r=0;
        int l=0;
        if(node->left!=nullptr)
        {
           l = this->fuckMyBack(node->left,a);
        }

        if(node->right!=nullptr)
        {
            r= this->fuckMyBack(node->right,a);
        }
        a.push(node->val+l);
        a.push(node->val+r);
        a.push(node->val+r+l);

        int now_val=(l>r)?l:r;
        now_val+=node->val;
        now_val=(node->val>now_val)?node->val:now_val;
        // cout<<"now node"<<node->val<<"now val"<<now_val<<endl;
        return now_val;
    }
};