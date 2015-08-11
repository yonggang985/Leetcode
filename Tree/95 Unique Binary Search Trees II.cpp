/*	95	Unique Binary Search Trees II
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Hide Tags Tree Dynamic Programming
Hide Similar Problems (M) Unique Binary Search Trees (M) Different Ways to Add Parentheses

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
    TreeNode* clone(TreeNode* root)
    {
        if(root==NULL)
        {
            return NULL;
        }
        TreeNode* newroot = new TreeNode(root->val);
        newroot->left = clone(root->left);
        newroot->right = clone(root->right);
        return newroot;
    }
    
    vector<TreeNode*> generateTrees(int n) 
    {
        vector<TreeNode*> res(1,NULL); //vector to save the result.
        for(int i=1; i<=n; i++)
        {
            vector<TreeNode*> tmp;
            for(int j=0; j<res.size(); j++)
            {
                TreeNode* oldroot = res[j];
                TreeNode* root = new TreeNode(i); //root is the newtree's root node.
                TreeNode* target = clone(oldroot);//clone the oldtree, and target pointer to the newtree's root.
                root->left = target;
                tmp.push_back(root);
                if(oldroot!=NULL)
                {
                    TreeNode* tmpold = oldroot;
                    while(tmpold->right!=NULL)
                    {
                        TreeNode* nonroot = new TreeNode(i);
                        TreeNode* tright = tmpold->right;
                        tmpold->right = nonroot;
                        nonroot->left = tright;
                        TreeNode* target = clone(oldroot);
                        tmp.push_back(target);
                        tmpold->right = tright;
                        tmpold = tmpold->right;
                    }
                    tmpold->right = new TreeNode(i);
                    TreeNode* target = clone(oldroot);
                    tmp.push_back(target);
                    tmpold->right = NULL;
                }
            }
            res = tmp;
        }
        return res;
    }
};