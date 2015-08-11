/*199	Binary Tree Right Side View
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.

Hide Tags Tree Depth-first Search Breadth-first Search
Hide Similar Problems (M) Populating Next Right Pointers in Each Node

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
 
 
 //DFS, root,right,left. parameter level control only input one element of this level.
class Solution {
public:
    void traversal(TreeNode* root,int level,vector<int> &res) 
    {
         if(root==NULL)
        {
            return ;
        }
        if(res.size()<level)
        {
            res.push_back(root->val);
        }
        traversal(root->right,level+1,res);
        traversal(root->left,level+1,res);
    }
    
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;
        traversal(root,1,res);
        return res;
    }
};