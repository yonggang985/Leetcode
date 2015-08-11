/*117	Populating Next Right Pointers in Each Node II
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
Hide Tags Tree Depth-first Search
Hide Similar Problems (M) Populating Next Right Pointers in Each Node

*/


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
 //time: O(n) , space: O(1)
 // level-order traversal
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
       TreeLinkNode* now = root; //this pointer scan current level left from right.
       TreeLinkNode* tail = NULL;//next level's scan pointer left from right.
       TreeLinkNode* head = NULL;//save next level's far left node's position.
       while(now != NULL) 
       {
           if(now->left != NULL) //case: now->left != NULL
           {
               if(tail != NULL)
               {
                   tail->next = now->left;
                   tail = tail->next;
               }
               else
               {
                   tail = now->left;
                   head = tail;
               }
           }
           if(now->right != NULL) //case: now->right != NULL
           {
               if(tail != NULL)
               {
                   tail->next = now->right;
                   tail = tail->next;
               }
               else
               {
                   tail = now->right;
                   head= tail;  
               }
           }
           if((now=now->next)==NULL) //case: now->left==NULL && now->right==NULL then now=now->next.
           {
               now = head; //last now==NULL means now is the last node->next, then now=head(new level).  
               tail = NULL; 
               head = NULL;
           }
       }
    }
};