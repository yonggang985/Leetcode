/*	230	Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags Tree Binary Search
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
 
 //BST Order traversal: left,root,right. 
class Solution {
public:
    void kthSmallestHelper(TreeNode* root,int &k,int &res)
    {
        if(k!=0 && root->left!=NULL)
        {
            kthSmallestHelper(root->left,k,res);
        }
        if(--k==0)   
        {
            res = root->val;
            return;
        }
        if(k!=0 && root->right!=NULL)
        {
            kthSmallestHelper(root->right,k,res);
        }
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        int res;
        kthSmallestHelper(root,k,res);
        return res;
    }
};