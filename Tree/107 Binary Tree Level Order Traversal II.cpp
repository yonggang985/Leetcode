/*107	Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
 
 //first level order traveral the tree, then reverse the vector<vector<int> > res.
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int> > res;
        queue<TreeNode* > q;
        if(root != NULL)
        {
            q.push(root);
        }
        while(!q.empty())  
        {
            vector<int> level; 
            int len = q.size(); // get the total element in queue.
            for(int i=0; i<len; ++i)
            {
                TreeNode* node = q.front(); 
                level.push_back(node->val); //save the node which will be pop later.
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
            res.push_back(level);  //save vector<int> level.
        }
        std::reverse(res.begin(),res.end()); //reverse res's element.
        return res;
    }
};