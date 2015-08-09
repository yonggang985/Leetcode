/*	103	Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Hide Tags Tree Breadth-first Search Stack
Hide Similar Problems (E) Binary Tree Level Order Traversal
Have you met this question in a real interview? Yes  No
Discuss


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root!=NULL)
        {
            q.push(root);
        }
        int flag = 1;
        while(!q.empty())
        {
            int len = q.size();
            vector<int> level;
            for(int i=0; i<len; ++i)
            {
                TreeNode* node = q.front();
                level.push_back(node->val);
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
            if(flag%2==0)
            {
                reverse(level.begin(),level.end());
            }
            ++flag;
            ans.push_back(level);
        }
        return ans;
    }
};