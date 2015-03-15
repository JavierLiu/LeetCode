// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author : Javier Liu
// Date   : 2015-03-15

/********************************************************************************** 
* 
* Given a binary tree
* struct TreeLinkNode {
*     TreeLinkNode *left;
*     TreeLinkNode *right;
*     TreeLinkNode *next;
* }
* Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
* Initially, all next pointers are set to NULL.
* 
* Note:
*       You may only use constant extra space.
*       You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).  
* 
* For example, Given the following perfect binary tree,
*                       1                                     1 => null
*                     /  \                                   /  \
*                    2    3            ======>              2 => 3 => null
*                   / \  / \                               / \  / \
*                  4  5  6  7                             4=>5=>6=>7 => null
*
* Solution: conect right child to brother's child when traverse
*              
**********************************************************************************/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        if (root->left != NULL && root->right != NULL)
            root->left->next = root->right;
        if (root->right != NULL && root->next != NULL && root->next->left != NULL)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
};