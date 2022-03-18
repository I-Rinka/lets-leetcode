/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||p==NULL||q==NULL)
        {
            return NULL;
        }

        unordered_map<TreeNode*,TreeNode*>parentMap;
        this->GenParent(root,parentMap);

        unordered_set<TreeNode*>visit;
        TreeNode*curNode=p;
        visit.insert(curNode);
        auto find=parentMap.find(curNode);
        while((find=parentMap.find(curNode))!=parentMap.end())
        {
            curNode=(*find).second;
            visit.insert(curNode);
        }

        curNode=q;
        if(visit.find(curNode)!=visit.end())
        {
            return curNode;
        }
        while((find=parentMap.find(curNode))!=parentMap.end())
        {   
            curNode=(*find).second;
            if(visit.find(curNode)!=visit.end())
            {
                return curNode;
            }
        }
        return NULL;
    }
    void GenParent(TreeNode*node,unordered_map<TreeNode*,TreeNode*>&hashmap)
    {
        if(node->left!=NULL)
        {
            hashmap[node->left]=node;
            this->GenParent(node->left,hashmap);
        }
        if(node->right!=NULL)
        {
            hashmap[node->right]=node;
            this->GenParent(node->right,hashmap);
        }
    }
};