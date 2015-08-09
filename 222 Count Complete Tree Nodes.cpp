/*	222	Count Complete Tree Nodes
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Hide Tags Tree Binary Search

*/


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
    int countNodes(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        TreeNode* lef = root;
        TreeNode* rig = root;
        int hlef = 0;
        int hrig = 0;
        while(lef!=NULL)
        {
            ++hlef;
            lef = lef->left;
        }
        while(rig!=NULL)
        {
            ++hrig;
            rig = rig->right;
        }
        if(hlef==hrig)
        {
            return pow(2,hlef)-1;
        }
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};