/*94	Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Hide Tags Tree Hash Table Stack
Hide Similar Problems (M) Validate Binary Search Tree (M) Binary Tree Preorder Traversal (H) Binary Tree Postorder Traversal (M) Binary Search Tree Iterator (M) Kth Smallest Element in a BST

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
 
 //DFS, left root right
class Solution {
public:
    vector<int> traversal(TreeNode* node,vector<int> &res)
    {
        if(node->left!=NULL)
        {
            traversal(node->left,res);
        }
        res.push_back(node->val);
        if(node->right!=NULL)
        {
            traversal(node->right,res);
        }
        return res;
        
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root==NULL)
        {
            return res;
        }
        TreeNode* node = root;
        return traversal(node,res);
    }
    
};
