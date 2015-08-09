/*	114	Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

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
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        TreeNode* now = root;
        while(now!=NULL)
        {
            if(now->left!=NULL)
            {
                TreeNode* pre = now->left;
                while(pre->right!=NULL) //pre pointer the right most node.
                {
                    pre = pre->right;
                }
                pre->right = now->right;  
                now->right = now->left; //right pointer point to the left
                now->left = NULL; //close the left pointer.
            }
            now = now->right;
        }
    }
};