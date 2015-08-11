/*Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        return helper(root->left,root->right); 
    }
    
    bool helper(TreeNode* leftNode,TreeNode* rightNode)
    {
        if(leftNode==NULL && rightNode==NULL) 
        {
            return true;
        }
        else if(leftNode==NULL || rightNode==NULL)
        {
            return false;
        }
        
        if(leftNode->val !=rightNode->val)
        {
            return false;
        }
        
        return helper(leftNode->left,rightNode->right) && helper(leftNode->right,rightNode->left);
    }
};