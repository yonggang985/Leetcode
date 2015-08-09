/*	113	Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
 Tree Depth-first Search
Hide Similar Problems (E) Path Sum

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> res;  //save all the path
        vector<int> path; //save every sigle path
        findAllPath(root,sum,path,res); 
        return res;
    }
    
    //DFS  root,left,right
    void findAllPath(TreeNode* root,int sum,vector<int> &path,vector<vector<int>> &res)
    {
        if(root==NULL)
        {
            return ;
        }
        path.push_back(root->val); // push_back root->val first.
        if(root->left==NULL && root->right==NULL && root->val==sum)
        {
            res.push_back(path);
        }
        if(root->left != NULL)
        {
            findAllPath(root->left,sum-root->val,path,res);
        }
        if(root->right != NULL)
        {
            findAllPath(root->right,sum-root->val,path,res);
        }
        path.pop_back(); //don't meet any of above case.
    }
};