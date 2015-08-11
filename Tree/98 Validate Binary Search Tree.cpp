/*	98	Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Hide Tags Tree Depth-first Search
Hide Similar Problems (M) Binary Tree Inorder Traversal

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
class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        return isBST(root, NULL, NULL);
    }
    bool isBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) 
    {
        if(root==NULL) return true;
        if(minNode!=NULL && root->val<=minNode->val || maxNode!=NULL && root->val>=maxNode->val)
        {
            return false;
        }
        return isBST(root->left, minNode, root) && isBST(root->right, root, maxNode);
    }
};