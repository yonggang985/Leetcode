/*	124	Binary Tree Maximum Path Sum
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

Hide Tags Tree Depth-first Search
Hide Similar Problems (E) Path Sum (M) Sum Root to Leaf Numbers


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
    int dfsMaxPath(TreeNode* root,int& maxPath)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lef = max(0,dfsMaxPath(root->left,maxPath));
        int rig = max(0,dfsMaxPath(root->right,maxPath));
        maxPath = max(maxPath,lef+rig+root->val);
        return root->val+max(lef,rig);
    }
    int maxPathSum(TreeNode* root) 
    {
        int maxPath = INT_MIN;
        dfsMaxPath(root,maxPath);
        return maxPath;
    }
};