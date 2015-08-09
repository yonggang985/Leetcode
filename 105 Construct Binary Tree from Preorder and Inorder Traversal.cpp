/*	105	Construct Binary Tree from Preorder and Inorder Traversal
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Hide Tags Tree Array Depth-first Search
Hide Similar Problems (M) Construct Binary Tree from Inorder and Postorder Traversal

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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return create(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* create(vector<int>& preorder,vector<int>& inorder,int ps,int pe,int is,int ie)
    {
        if(ps>pe)
        {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[ps]);
        int pos;
        for(int i=is; i<=ie; i++)
        {
            if(inorder[i]==node->val)
            {
                pos = i;
                break;
            }
        }
        node->left = create(preorder,inorder,ps+1,ps+pos-is,is,pos-1);
        node->right = create(preorder,inorder,ps+1+pos-is,pe,pos+1,ie);
        return node;
    }
};



