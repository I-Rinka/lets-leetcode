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
    vector<vector<int>> ans;
    void traverse(vector<int>&currentQ,int currentSum,TreeNode*node,int targetSum)
    {
        currentSum+=node->val;
        currentQ.push_back(node->val);
        if(targetSum==currentSum&&node->left==nullptr&&node->right==nullptr)
        {
            ans.push_back(currentQ);
        }

        if(node->left!=nullptr)
        {
            this->traverse(currentQ,currentSum,node->left,targetSum);
        }

        if(node->right!=nullptr)
        {
            this->traverse(currentQ,currentSum,node->right,targetSum);
        }

        currentQ.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
        {
        
        }
        else
        {
            vector<int>vec;
            this->traverse(vec,0,root,targetSum);
        }
        return ans;
    }
};
