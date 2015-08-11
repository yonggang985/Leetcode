/*111	Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        int lef = minDepth(root->left);
        int rig = minDepth(root->right); 
        return (lef==0 || rig==0)? lef+rig+1 : min(lef,rig)+1;
    }
};