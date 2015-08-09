/*106	Construct Binary Tree from Inorder and Postorder Traversal
Construct Binary Tree from Inorder and Postorder Traversal Total Accepted: 36175 Total Submissions: 134619 My Submissions Question Solution 
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Hide Tags Tree Array Depth-first Search
Hide Similar Problems (M) Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        return create(postorder,inorder,0,postorder.size()-1,0,inorder.size()-1);
    }
    
    TreeNode* create(vector<int>& postorder,vector<int>& inorder,int ps,int pe,int is,int ie)
    {
        if(ps>pe)
        {
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[pe]);
        int pos;
        for(int i=is; i<=ie; i++)
        {
            if(inorder[i]==node->val)
            {
                pos = i;
                break;
            }
        }
        node->left = create(postorder,inorder,ps,pos-is+ps-1,is,pos-1);
        node->right = create(postorder,inorder,ps+pos-is,pe-1,pos+1,ie);
        return node;
    }
};