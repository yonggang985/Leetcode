/*	102	Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int> > ans;
        queue<TreeNode* > q;
        if(root != NULL)
        {
            q.push(root);
        }
        while(!q.empty())
        {
            int len = q.size(); //current queue's size
            vector<int> level;  
            for(int i=0; i<len; ++i) //travel one level
            {
                TreeNode *node = q.front();  //current queue's front node.
                level.push_back(node->val);  //save current level's element to a vector.
                if(node->left != NULL)
                {
                    q.push(node->left);
                }
                if(node->right != NULL)
                {
                    q.push(node->right);
                }
                q.pop();
            }
            ans.push_back(level);//save one level's vector
        }
        return ans;
    }
};