/*	173	Binary Search Tree Iterator
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags Tree Stack
Hide Similar Problems (M) Binary Tree Inorder Traversal (M) Flatten 2D Vector

*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) 
    {
        findFirst(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        if(st.empty())
        {
            return false;
        }
        return true;
    }

    /** @return the next smallest number */
    int next() 
    {
        TreeNode* top = st.top();
        st.pop();
        if(top->right!=NULL)
        {
            findFirst(top->right);
        }
        return top->val;
    }
    
    void findFirst(TreeNode* root)
    {
        TreeNode* p = root;
        while(p!=NULL)
        {
            st.push(p);
            p = p->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */