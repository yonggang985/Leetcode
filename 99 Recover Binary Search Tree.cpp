/*	99	Recover Binary Search Tree
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Hide Tags Tree Depth-first Search

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
 
 //DFS Inorder,left root right. 
class Solution {
private:
    TreeNode* first = NULL; //the first position that reverse.
    TreeNode* second = NULL; //the second posiont that reverse.
    TreeNode* prev = new TreeNode(INT_MIN);
public:
    void recoverTree(TreeNode* root)
    {
        traverse(root);
        swap(first->val,second->val);
    }
    
    void traverse(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        traverse(root->left);
        if(first==NULL && prev->val>=root->val)
        {
            first = prev;
        }
        if(first!=NULL && prev->val>=root->val)
        {
            second = root;
        }
        prev = root; 
        traverse(root->right);
    }
};