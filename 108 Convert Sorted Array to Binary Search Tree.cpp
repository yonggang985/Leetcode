/*108	Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Hide Tags Tree Depth-first Search
Hide Similar Problems (M) Convert Sorted List to Binary Search Tree

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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.empty())
        {
            return NULL;
        }
        return helper(nums,0,nums.size()-1);
    }
    TreeNode* helper(vector<int> nums,int low,int high)
    {
        if(low>high)
        {
            return NULL;
        }
        int mid = low + (high-low)/2; //get the mid position of the vector<int>
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(nums,low,mid-1); //recursion the left part.
        node->right = helper(nums,id+1,high); //recursion the right part.
        return node;
    }
};