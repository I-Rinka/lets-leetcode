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
    void traverse(TreeNode* node,vector<int>&ans)
    {
        if(node->left!=nullptr)
        {
            this->traverse(node->left, ans);
        }
        ans.push_back(node->val);
        if(node->right!=nullptr)
        {
            this->traverse(node->right, ans);
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        if(root!=nullptr)
        {
            this->traverse(root,ans);
            for(int i=0;i<ans.size()-1;i++)
            {
                if(ans[i]>=ans[i+1])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};