/*Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    int dfsHeight(TreeNode* root)   //DFS left,right,root 
    {
        if(root==NULL) 
        {
            return 0;
        }
        
        int leftHeight = dfsHeight(root->left);  //left sub tree.
        if(leftHeight==-1)  //when the left sub tree is not balance, the tree is not balance.
        {
            return -1;
        }
        
        int rightHeight = dfsHeight(root->right); //right
        if(rightHeight==-1) //when the right sub tree is not balance, the tree is not balance.
        {
            return -1;
        }
        
        if(abs(leftHeight-rightHeight)>1)  // judge whether current node is balance.
        {
            return -1;
        }
        
        return max(leftHeight,rightHeight) + 1; //current root height
    }
    bool isBalanced(TreeNode* root) 
    {
        return dfsHeight(root) != -1; 
    }
};